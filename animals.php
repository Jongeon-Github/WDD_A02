<!--
 Filename: animals.php
 Project: Assignment 2
 By: Jongeon Lee
 Student number: 8790144
 Date: Oct 14, 2023
 Description: A PHP script that displays information about a selected animal based on user input.
-->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Animal Serve in PHP</title>
</head>
<body>
    <?php

    // Initialize variables to store user input
    $name = '';
    $animal = '';

    // Get query parameters from the URL
    $query_string = $_SERVER['QUERY_STRING'];
    parse_str($query_string, $params);

    // Retrieve the user's name and selected animal if provided
    if (isset($params['name'])) {
        $name = $params['name'];
    }

    if (isset($params['animal'])) {
        $animal = $params['animal'];
    }

    // Set the page title dynamically
    echo "<script>document.title = 'Animal Serve in PHP';</script>";

    // Display header and greeting
    echo "<div class=\"headerArea\">Pet Facts!</div>\n";
    echo "<div class=\"division-line\"></div>\n";
    echo "<div class=\"greetingArea\">\n";
    echo "Hello, $name! You selected to learn more about the $animal.\n";
    echo "<br>Look how amazing they can be!\n";
    echo "</div>\n";
    echo "<div class=\"division-line\"></div>\n";
    echo "<div class=\"imageArea\">\n";
    echo "<img src=\"theZoo/$animal.png\" alt=\"image\">\n";
    echo "</div>\n";

    // Read and display information from a text file
    $filePath = "theZoo/$animal.txt";
    $fileContents = file($filePath);

    if ($fileContents === false) {
        echo "Error: Can't open the file for reading.";
    } else {
        $count = 1;
        echo "<div class=\"description-line\">";
        foreach ($fileContents as $line) {
            if ($count == 1) {
                echo "<div class=\"description-line-first\" style='font-size: 22px;'>$line</div>\n";
            } else if ($count == 2) {
                echo "<div class=\"description-line-second\" style='font-size: 25px;'>$line</div>\n";
            } else {
                echo "<div class=\"description-line-third\" style='font-size: 18px;'>$line</div>\n";
            }
            $count++;
        }
        echo "</div>\n";
    }

    echo "</body>\n</html>";
    ?>

</body>
</html>
