<!DOCTYPE html>
<html>
<title>Railway</title>
<body bgcolor="pink"><center><b>
<h1>Railway Reservation System</h1></b></center></br>
<form action="SQLsignIn.php" method="post"><fieldset><legend>Indivisual Registration</legend>
  User ID:
  <input type="text" name="username" required><br>
  Password:
  <input type="password" name="psw" required></br>
Confirm Password:
 <input type="password" name="psw" required></br>
Preferred Language:
<input list="languages" name="language" required>
<datalist id="languages">
<option value="Hindi">
<option value="English">
</datalist>
</br>
  Full Name:
  <input type="text" name="fullname" required></br>
  Gender:<input list="gender" name="gender" required>
<datalist id="gender">
<option value="Male">
<option value="Female">
<option value="other">
</datalist></br>
  Marital Status:<input list="Marital_status" name="Marital_status" required>
<datalist id="Marital_status">
<option value="Married">
<option value="Unmarried"></datalist></br>
 Date of Birth:
<input type="date" name="dob" value="DOB" max="2017-11-15"required></br>
Occupation:<input type="text" name="occupation" required></br>
Aadhar Number:<input type="aadhar_number" name="aadhar number">(optional) </br>
Country:<input type="text" name="country_name" required></br>
  Email:
  <input type="email" name="email" value="Email" required></br>
 Mobile Number:<input type="isd-tel" name="mobile" value="Mobile Number" required></br>
Complete Address:<input type="text" name="address"></br>
Pin Code:<input type="number" name="pin" size="6" required></br>
City:<input type="text" name="city" required></br>
State:<input type="text" name="state" required></br>
<input type="submit" value="SIGN UP"><input type="reset" value="Reset">
</fieldset>
</form>
</body>
</html>
