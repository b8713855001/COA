<!DOCTYPE html>
<html>
<head>
</head>
<body>
<?php
 $url_a="/opt/lampp/htdocs/SQLlogIn.php";
 $data_a=file_get_contents($url_a);
echo $data_a;
include '/opt/lampp/htdocs/SQLlogIn.php';
echo $username."h";
?>
</body>
</html>
