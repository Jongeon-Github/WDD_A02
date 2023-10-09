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
    $name = $_POST["name"];
    $selectedAnimal = $_POST["animal"];

    echo "<div class='headerArea'>Pet Facts!</div>";
    echo "<div class='division-line'></div>";
    echo "<div class='greetingArea'>";
    echo "Hello, $name! You selected to learn more about the $selectedAnimal.";
    echo "<br>Look how amazing they can be!";
    echo "</div>";
    echo "<div class='division-line'></div>";
    echo "<div class='imageArea'>";
    echo "<img src='theZoo/$selectedAnimal.png' alt='image'>";
    echo "</div>";

    $filePath = "theZoo/$selectedAnimal.txt";
    if (file_exists($filePath)) {
        $lines = file($filePath);
        $lineNumber = 1;
        echo "<div class='description-line'>";
        foreach ($lines as $line) {
            if (trim($line) != "") {
                if ($lineNumber == 1) {
                    echo "<div class='description-line-first' style='font-size: 18px;'>" . trim($line) . "</div>";
                } elseif ($lineNumber == 2) {
                    echo "<div class='description-line-second' style='font-size: 20px;'>" . trim($line) . "</div>";
                } else {
                    echo "<div class='description-line-third' style='font-size: 16px;'>" . trim($line) . "</div>";
                }
                $lineNumber++;
            }
        }
    } else {
        echo "Error: Can`t open file for reading";
    }
    echo "</div>";
    ?>
</body>
</html>
