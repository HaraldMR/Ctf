<!DOCTYPE html>
<html>
<head>
	<title>Login Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div class="login-box">
		<h1>Login</h1>
		<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
			<label for="username">Username:</label>
			<input type="text" name="username" id="username" required>

			<label for="password">Password:</label>
			<input type="password" name="password" id="password" required>

			<input type="submit" value="Login">
		</form>
	</div>

	<script src="script.js"></script>

	<?php
		// Check if the login form has been submitted
		if ($_SERVER['REQUEST_METHOD'] == 'POST') {
			// Retrieve the username and password from the POST request
			$username = $_POST['username'];
			$password = $_POST['password'];

            if ($username == 'admin' && $password == 'takethis') {
                // Redirect to flag page
                header('Location: flag.php');
                exit;
            } else {
                echo "Login failed.";
            }
		}
	?>
</body>
</html>
