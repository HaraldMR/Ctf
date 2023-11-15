<?php
session_start();

// If the user is not logged in, redirect them to the login page
if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("location: index.php");
    exit;
}

// Display the flag here
echo "Nicely done! CTFkom{D4T4b4s3S_R_DuM}";
?>
