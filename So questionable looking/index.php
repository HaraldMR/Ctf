<?php
session_start();
$_SESSION['loggedin'] = false;
// Check if the login form has been submitted
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Retrieve the username and password from the POST request
    $username = $_POST['username'];
    $password = $_POST['password'];

    if ($username == 'admin' && $password == 'nut') {
        // Set session variables to indicate that the user is logged in
        $_SESSION['loggedin'] = true;

        // Redirect to flag page
        header('Location: flag.php');
        exit;
    } else {
        echo "<h1>Login failed.</h1>";
    }
}
?>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div class="login-box">
		<h1>Login</h1>
		<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
			<label for="username">Username:</label>
			<input type="text" name="username" id="username">

			<label for="password">Password:</label>
			<input type="password" name="password" id="password">

			<input type="submit" value="Login">
		</form>
	</div>

	<script src="script.js"></script>
</body>
</html>
