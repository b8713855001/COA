<?php
$username=$_POST['username'];
$psw=$_POST['psw'];
$language=$_POST['language'];
$fullname=$_POST['fullname'];
$gender=$_POST['gender'];
$Marital_status=$_POST['Marital_status'];
$dob=$_POST['dob'];
$occupation=$_POST['occupation'];
$aadhar_number=$_POST['aadhar_number'];
$country_name=$_POST['country_name'];
$email=$_POST['email'];
$mobile=$_POST['mobile'];
$address=$_POST['address'];
$pin=$_POST['pin'];
$city=$_POST['city'];
$state=$_POST['state'];
$link=mysqli_connect("localhost", "root", "", "User");
if($link===False){
    die("ERROR: Could not connect. " .mysqli_connect_error());
}
$sql = "INSERT INTO User_database VALUES ('$username','$psw','$language','$fullname', '$gender','$Marital_status','$dob','$occupation','$aadhar_number','$country_name','$email','$mobile','$address','$pin','$city','$state')";
if(mysqli_query($link, $sql)){
    echo "Records added successfully.";
    header('Location: LogIn.php');
} else{
    echo "ERROR: Could not able to execute $sql. " .mysqli_error($link);
    header('Location: signIn.php');
}/*
if ($conn->query($sql) === TRUE) {
    echo "Records added successfully.";
    header('Location: LogIn.php');
} else {
    echo "Error:Could not able to execute  " . $sql . "<br>" . $conn->error;
    header('Location: signIn.php');
}*/
mysqli_close($conn);
?>
