<!DOCTYPE html>
<html>
<head>
	<title>Login Page</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div class="login-box">
		<h1>Login</h1>
		<form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST" onsubmit="return ValidateForm()">
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

			// Create a connection to the MySQL server using the environment variables
			$conn = mysqli_connect(getenv('DB_HOST'), getenv('DB_USER'), getenv('DB_PASS'));

			// Select the database to use
			mysqli_select_db($conn, 'ctf_DB');

			// Construct the SQL query to check if the user exists
			$query = "SELECT * FROM users WHERE username = '{$username}' AND password = '{$password}'";

			// Execute the SQL query
			$result = mysqli_query($conn, $query);

			// Check if the query returned any rows
			if (mysqli_num_rows($result) > 0) {
				// The user exists, log them in
				$row = mysqli_fetch_assoc($result);
				if ($row['username'] == 'admin' && $row['password'] == 'password') {
					// Redirect to flag page
					header('Location: flag.php');
					exit;
				} else {
					echo "<h1>Login failed.</h1>";
				}
			} else {
				// The user does not exist or the password is incorrect
				echo "<h1>Login failed.</h1>";
			}

			// Close the database connection
			mysqli_close($conn);
		}
	?>
</body>
</html>
