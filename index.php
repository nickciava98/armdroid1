<?php
	exec("sudo chmod 777 /dev/ttyACM0");
	
	include "php_serial.class.php";
 
	print("	<link rel = 'icon' href = 'favicon.ico'>");
	print("	<link rel = 'apple-touchstartup-image' href = 'favicon.ico'>");
	print("	<link rel = 'apple-touch-icon' href = 'favicon.ico'>");
	print("	<html xmlns = 'http://www.w3.org/1999/xhtml'>
				<head>
					<meta http-equiv = 'Content-Type' content = 'text/html; charset=UTF-8'/>

					<title>
						Armdroid 1
					</title>

					<link href = 'screen.css' rel = 'stylesheet' media = 'screen' type = 'text/css' />
				</head>

				<body>
					<center>
						<span style = 'font-family: Arial; font-size: 120px; color: #FFFFFF;'>
							Robot v6.0
						</span>
						
						<br/><br/><br/>
						
						<form action = '#' method = 'post'>			
							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 80px; background-color: blue' type = 'submit' name = 'auto' value = 'AUTO'/>
									</td>
									
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 80px; background-color: red' type = 'submit' name = 'stop' value = 'STOP'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 70px; background-color: yellow' type = 'submit' name = 'base_avanti' value = 'BASE Avanti'/>
									</td>
									
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 65px; background-color: yellow' type = 'submit' name = 'base_indietro' value = 'BASE Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 60px; background-color: green' type = 'submit' name = 'spalla_avanti' value = 'SPALLA Avanti'/>
									</td>
								
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: green' type = 'submit' name = 'spalla_indietro' value = 'SPALLA Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: grey' type = 'submit' name = 'braccio_avanti' value = 'BRACCIO Avanti'/>
									</td>
								
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 50px; background-color: grey' type = 'submit' name = 'braccio_indietro' value = 'BRACCIO Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: violet' type = 'submit' name = 'polso1_avanti' value = 'POLSO1 Avanti'/>
									</td>
								
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: violet' type = 'submit' name = 'polso1_indietro' value = 'POLSO1 Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: brown' type = 'submit' name = 'polso2_avanti' value = 'POLSO2 Avanti'/>
									</td>
								
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 55px; background-color: brown' type = 'submit' name = 'polso2_indietro' value = 'POLSO2 Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>

							<table>
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 65px; background-color: white' type = 'submit' name = 'mano_avanti' value = 'MANO Avanti'/>
									</td>
								
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 60px; background-color: white' type = 'submit' name = 'mano_indietro' value = 'MANO Indietro'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/><br/><br/><br/>
							
							<span style = 'font-family: Arial; font-size: 80px; color: #FFFFFF;'>
								Only for iOS Users
							</span>
							
							<br><br><br>
						</form>
						
						<form action = 'voice.php' method = 'post'>							
							<table>				
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 80px' type = 'submit' name = 'voice' value = 'VOICE'/>
									</td>
								</tr>
							</table>							
						</form>
						
						<br/><br/><br/><br/><br/><br/>
						
						<span style = 'font-family: Arial; font-size: 45px; color: #FFFFFF;'>
							Copyright (c) 2016 Niccol&ograve Ciavarella.
						</span> 
						
						<br/>
						
						<span style = 'font-family: Arial; font-size: 45px; color: #FFFFFF;'>
							All rights reserved.
						</span>
					</center>
				</body>	
			</html>");
 
	$serial = new phpSerial;
	 
	$serial->deviceSet("/dev/ttyACM0"); 
	$serial->confBaudRate(9600);
	$serial->confParity("none");
	$serial->confCharacterLength(8);
	$serial->confStopBits(1);
	$serial->confFlowControl("none");
	$serial->deviceOpen();
	
	if(isset($_POST["auto"]))
	{
		$serial->sendMessage("0");
	}
	
	if(isset($_POST["base_avanti"]))
	{
		$serial->sendMessage("1");
	}
	
	if(isset($_POST["base_indietro"]))
	{
		$serial->sendMessage("2");
	}
	
	if(isset($_POST["spalla_avanti"]))
	{
		$serial->sendMessage("4");
	}
	
	if(isset($_POST["spalla_indietro"]))
	{
		$serial->sendMessage("5");
	}
	
	if(isset($_POST["braccio_avanti"]))
	{
		$serial->sendMessage("6");
	}
	
	if(isset($_POST["braccio_indietro"]))
	{
		$serial->sendMessage("7");
	}
	
	if(isset($_POST["polso1_avanti"]))
	{
		$serial->sendMessage("8");
	}
	
	if(isset($_POST["polso1_indietro"]))
	{
		$serial->sendMessage("9");
	}
	
	if(isset($_POST["polso2_avanti"]))
	{
		$serial->sendMessage("a");
	}
	
	if(isset($_POST["polso2_indietro"]))
	{
		$serial->sendMessage("b");
	}
	
	if(isset($_POST["mano_avanti"]))
	{
		$serial->sendMessage("c");
	}
	
	if(isset($_POST["mano_indietro"]))
	{
		$serial->sendMessage("d");
	}
	
	if(isset($_POST["stop"]))
	{
		$serial->sendMessage("3");
	}

	$serial->deviceClose();
?>
