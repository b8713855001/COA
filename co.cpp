#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<cmath>
int a[16],e=0,gt=0;
bool I=0;
using namespace std;
int Int(string R)
{
   int l=R.length(),i=0,s=1;
   while(l>0)
   {
       i+=s*(R[l-1]-'0');
       s*=10;
       l--;
   }
   return i;
}
int Decimal(string S)
{
  int i=1;
  int j=0;
  int l=S.length();
  for(int k=l-1;k>=0;k--)
  {
    j+=i*(S[k]-'0');
    i=i*2;
  }
  return j;
}
int Reg(string S)
{
   int l=S.length(),s;
   if(l==2)
   s=(S[1]-'0');
   else
   s=((S[1]-'0')*10+(S[2]-'0'));
   return s;
}
string fun(int p)
{
   string S="";
   while(p>=2)
   {
       S+=(p%2+'0');
       p=p/2;
   }
   S+=(p+'0');
   int l=S.length();
   if(l==1)
    S+="000";
   else if(l==2)
   S+="00";
   else if(l==3)
   S+="0";
   reverse(S.begin(),S.end());
   return S;
}
string fun1(int p,int r)
{
     string S="";
   while(p>=2)
   {
       S+=(p%2+'0');
       p=p/2;
   }
   S+=(p+'0');
   int l=S.length();
   for(int i=1;i<=r-l;i++)
   S+="0";
   reverse(S.begin(),S.end());
   return S;
}
string ADD(string P,string Q, string R)
{
          string E="";
         E+="00000";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]+a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]+r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Sub(string P,string Q,string R)
{
         string E="";
         E+="00001";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]-a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]-r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Mul(string P,string Q,string R)
{
       string E="";
         E+="00010";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]*a[lr];
                  char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]*r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Div(string P,string Q,string R)
{
       string E="";
         E+="00011";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]/a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]/r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Mod(string P,string Q,string R)
{
        string E="";
         E+="00100";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]%a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]%r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string And(string P,string Q,string R)
{
    string E="";
         E+="00110";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]&a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]&r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Or(string P,string Q,string R)
{
       string E="";
         E+="00111";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]|a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]|r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Lsl(string P,string Q,string R)
{
       string E="";
         E+="01010";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]<<a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]<<r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
string Mov(string P,string R)
{
      string E="";
       E+="01001";
       int lp=Reg(P);
       char ch=R[0];
       if(ch=='r')
       {
          int lr=Reg(R);
          I=0;
          a[lp]=a[lr];
          char ph=I+'0';
             E+=ph+fun(lp)+fun(lr);
       }
       else
       {
             I=1;
             char ph=I+'0';
             int r=Int(R);
             a[lp]=r;
             E+=ph+fun(lp)+"00"+fun1(r,16);
       }
       return E;
}
string Ld(string P,string R)
{
      string E="";
       E+="01110";
       int lp=Reg(P);
       I=1;
       char ph=I+'0';
       E+=ph;
       int l=R.length();
       int x=R.find('[');
       int y=0,z=1;int b=x;;
       while(x>0)
       {
          y+=z*(R[x-1]-'0');
          z*=10;x--;
       }
       int lr=0;
       z=1;
       while(l>b+3)
       {
         lr+=z*(R[l-2]-'0');
         z=z*10;
         l--;

       }
       a[lp]=*(&a[lr]+x);
       E+=fun(lp)+fun(lr)+"00"+fun1(y,16);
       return E;
}
string St(string P,string R)
{
       string E="";
         E+="01111";
         int lp=Reg(P);
         I=1;char ph=I+'0';
         E+=ph;
       int l=R.length();
       int x=R.find('[');
       int y=0,z=1;int b=x;;
       while(x>0)
       {
          y+=z*(R[x-1]-'0');
          z*=10;x--;
       }
       int lr=0;
       z=1;
       while(l>b+3)
       {
         lr+=z*(R[l-2]-'0');
         z=z*10;
         l--;

       }
       int r=*(&a[lr]+x)=a[lp];
           E+=fun(lp)+fun(lr)+"00"+fun1(y,16);
           return E;
}
string Not(string P,string R)
{
      string E="";
        E+="01000";
       int lp=Reg(P);
       char ch=R[0];
       if(ch=='r')
       {
          int lr=Reg(R);
          I=0;
          a[lp]=(~a[lr]);
          char ph=I+'0';
             E+=ph+fun(lp)+fun(lr);
       }
       else
       {
         int r=Int(R);
         I=1;
         a[lp]=(~r);
         char ph=I+'0';
             E+=ph+fun(lp)+"00"+fun1(r,16);
       }
       return E;
}
string Cmp(string P,string R)
{
      string E="";
         E+="00101";
         int lp=Reg(P);
         char ch=R[0];
         if(ch=='r')
         {
            I=0;
            char ph=I+'0';
            int lr=Reg(R);
            if(a[lp]==a[lr])
            {
                  e=1;
                  gt=0;
                  E+=ph+fun(lp)+fun(lr);
            }
            else if(a[lp]>a[lr])
            {
                  gt=1;e=0;
                  E+=ph+fun(lp)+fun(lr);
            }
            else
            {
                  gt=0;e=0;
                  E+=ph+fun(lp)+fun(lr);
            }
          }
          else
          {
             int r=Int(R);
             I=1;
             if(a[lp]==r)
             {
              e=1;gt=0;
              char ph=I+'0';
                  E+=ph+fun(lp)+"00"+fun1(r,16);
             }
             else if(a[lp]>r)
             {
                  gt=1;e=0;
                   char ph=I+'0';
                  E+=ph+fun(lp)+"00"+fun1(r,16);
             }
             else
             {
                 e=0;
                 char ph=I+'0';
                    gt=0;
                  E+=ph+fun(lp)+"00"+fun1(r,16);
             }
         }
return E;
}
string Lsr(string P,string Q,string R)
{
      string E="";
         E+="01011";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         int jk=ceil(log2(a[lq]));
         string F=fun1(a[lq],jk);
         string G="";int count=0;
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               for(int h=0;h<a[lr];h++)
               {
                    if(h<=jk)
                    {
                    count++;
                      G+="1";
                    }
                    else
                    {
                       break;
                    }
               }
               int h=0;
               while(count<jk)
               {
                   G+=F[h];
                   h++;count++;
               }
               a[lp]=Decimal(G);
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           int lr=Int(R);
           for(int h=0;h<lr;h++)
               {
                    if(h<=jk)
                    {
                    count++;
                      G+="1";
                    }
                    else
                    {
                       break;
                    }
               }
               int h=0;
               while(count<jk)
               {
                   G+=F[h];
                   h++;count++;
               }
               a[lp]=Decimal(G);
             I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(lr,16);
         }
         return E;
}
string Asr(string P,string Q,string R)
{
      string E="";
         E+="01100";
         int r;
         int lp=Reg(P);
         int lq=Reg(Q);
         char ch=R[0];
         if(ch=='r')
         {
               int lr=Reg(R);
               I=0;
               a[lp]=a[lq]>>a[lr];
               char ph=(I+'0');
                  E+=ph+fun(lp)+fun(lq)+fun(lr);
         }
         else
         {
           r=Int(R);
           a[lp]=a[lq]>>r;
           I=1;
             char ph=(I+'0');
             E+=ph+fun(lp)+fun(lq)+"00"+fun1(r,16);
         }
         return E;
}
int main()
{
     ifstream ci;
     ci.open("fh.txt");
     ofstream cou;
     cou.open("fh1.txt");
     string S,P,Q,R,T,Rt="";
     int *ptr;
     int fgh;
    // ci>>fgh;
while(!ci.eof())
{
     sd:
     ci>>S;
     if(S!=".encode" && S!=".print" && S!=".main")
     {
         goto sd;
     }
     else if(S==".main")
     {
         ci>>T;
         while(T!="ret")
         {
            ci>>T;
         }
         goto sd;
     }
     else
     {
        ci>>T;
     }
     if(T=="add")
     {
                ci>>P>>Q>>R;
                cou<<ADD(P,Q,R)<<endl;
     }
     else if(T=="sub")
     {
            ci>>P>>Q>>R;
            cou<<Sub(P,Q,R)<<endl;
     }
     else if(T=="mul")
     {
        ci>>P>>Q>>R;
        cou<<Mul(P,Q,R)<<endl;
     }
     else if(T=="div")
     {
         ci>>P>>Q>>R;
         cou<<Div(P,Q,R)<<endl;

     }
     else if(T=="mod")
     {
        ci>>P>>Q>>R;
        cou<<Mod(P,Q,R)<<endl;
     }
     else if(T=="and")
     {
        ci>>P>>Q>>R;
        cou<<And(P,Q,R)<<endl;
     }
     else if(T=="or")
     {
        ci>>P>>Q>>R;
        cou<<Or(P,Q,R)<<endl;
     }
     else if(T=="lsl")
     {
         ci>>P>>Q>>R;
         cou<<Lsl(P,Q,R)<<endl;
     }
     else if(T=="lsr")
     {
         ci>>P>>Q>>R;
         cou<<Lsr(P,Q,R)<<endl;
     }
     else if(T=="asr")
     {
         ci>>P>>Q>>R;
         cou<<Asr(P,Q,R)<<endl;
     }
     else if(T=="ret")
     {
         string F;
         cou<<"10100"<<endl;
         ci.seekg(0,ios::beg);
         ci>>F;
         while(F!="call")
         ci>>F;
         ci>>F;
         goto sd;
     }
     else if(T=="nop")
     {
       cou<<"10010"<<endl;
     }
     else if(T=="call")
     {
         ci>>P;
         string E="",F;
         E+="10011";
         cou<<E<<&P<<endl;
         ci.seekg(0,ios::beg);
         ci>>F;
         while(F!=P)
         {
               if(F=="call")
               ci>>F;
               ci>>F;
         }
         goto sd;
     }
     else if(T=="b")
     {
        ci>>P;
         string E="",F;
         E+="10010";
         cou<<E<<&P<<endl;
         ci.seekg(0,ios::beg);
         /*ci>>F;
         P+=":";
         while(F!=P)
         ci>>F;
         ci>>F;*/
         ci>>F;
         while(F!=P)
         {
               if(F=="b")
               ci>>F;
               ci>>F;
         }
         goto sd;
     }
     else if(T=="beq")
     {
         ci>>P;
         string E="",F;
         E+="10000";cou<<E<<&P<<endl;
         if(e==1)
         {
                   ci.seekg(0,ios::beg);
                   /*ci>>F;
                   P+=":";
                   while(F!=P)
                   ci>>F;
                   ci>>F;*/
                   ci>>F;
                   while(F!=P)
                   {
                          if(F=="beq")
                          ci>>F;
                          ci>>F;
                   }
                   goto sd;
         }
     }
     else if(T=="bgt")
     {
        ci>>P;
         string E="",F;
         E+="10001";
         cou<<E<<&P<<endl;
         if(gt==1)
         {
               ci.seekg(0,ios::beg);
                ci>>F;
                while(F!=P)
                {
                    if(F=="bgt")
                    ci>>F;
                    ci>>F;
                 }
                /*   ci>>F;
                   P+=":";
                   while(F!=P)
                   ci>>F;
                   ci>>F;
                   */
                goto sd;
         }
     }
     else if(T=="cmp")
     {
         ci>>P>>R;
         cou<<Cmp(P,R)<<endl;
     }
     else if(T=="mov")
     {
        ci>>P>>R;
       cou<<Mov(P,R)<<endl;
     }
     else if(T=="not")
     {
            ci>>P>>R;
            cou<<Not(P,R)<<endl;
     }
     else if(T=="ld")
     {
        ci>>P>>R;
        cou<<Ld(P,R)<<endl;
     }
     else if(T=="st")
     {
         ci>>P>>R;
        cou<<St(P,R)<<endl;
     }
     else if(S==".print")
     {
             int ll=Reg(T);
             cout<<"r"<<ll<<"="<<a[ll]<<endl;
     }
}
     return 0;
}
