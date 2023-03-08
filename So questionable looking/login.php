<?php
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
	if ($row['username'] == 'admin' && $row['password'] == 'ilikepasswordsthatarelongandhardtoremember') {
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
?>
