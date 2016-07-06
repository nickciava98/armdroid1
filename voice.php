<?php
	print("	<link rel = 'icon' href = 'favicon.ico'>");
	print("	<html xmlns = 'http://www.w3.org/1999/xhtml'>
				<head>
					<meta http-equiv = 'Content-Type' content = 'text/html; charset=UTF-8'/>

					<title>
						Armdroid 1 - Voice
					</title>

					<link href = 'screen.css' rel = 'stylesheet' media = 'screen' type = 'text/css' />
				</head>

				<body>
					<center>
						<span style = 'font-family: Arial; font-size: 120px; color: #FFFFFF;'>
							Voice
						</span>
						
						<br/><br/><br/>
						
						<form action = '#' method = 'post'>			
							<table>
								<tr>
									<td>
										<input style = 'width: 600px; height: 200px; font-size: 80px' type = 'text' name = 'text'/>
									</td>
								</tr>
							</table>
							
							<br/><br/><br/>
							
							<table>				
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 80px' type = 'submit' name = 'send' value = 'INVIA'/>
									</td>
								</tr>
							</table>

							<br/><br/><br/>
							
							<table>				
								<tr>
									<td>
										<input style = 'width: 500px; height: 200px; font-size: 80px' type = 'submit' name = 'home' value = 'HOME'/>
									</td>
								</tr>
							</table>
						</form>
					</center>
				</body>
			</html>");
			
	include "php_serial.class.php";
 
	$serial = new phpSerial;
		 
	$serial->deviceSet("/dev/ttyACM0");		 
	$serial->confBaudRate(9600);
	$serial->confParity("none");
	$serial->confCharacterLength(8);
	$serial->confStopBits(1);
	$serial->confFlowControl("none");
	$serial->deviceOpen();
	
	if(isset($_POST['text']) and isset($_POST['send']))
	{
		$cmd = $_POST["text"];
		
		if(strcmp($cmd, " Automatico ") == 0)
		{
			$serial->sendMessage("0");			
		}
		
		if(strcmp($cmd, " Base avanti ") == 0)
		{
			$serial->sendMessage("1");			
		}
		
		if(strcmp($cmd, " Base indietro ") == 0)
		{
			$serial->sendMessage("2");			
		}
		
		if(strcmp($cmd, " Spalla avanti ") == 0)
		{
			$serial->sendMessage("4");			
		}
		
		if(strcmp($cmd, " Spalla indietro ") == 0)
		{
			$serial->sendMessage("5");			
		}
		
		if(strcmp($cmd, " Braccio avanti ") == 0)
		{
			$serial->sendMessage("6");			
		}
		
		if(strcmp($cmd, " Braccio indietro ") == 0)
		{
			$serial->sendMessage("7");			
		}
		
		if(strcmp($cmd, " Polso uno avanti ") == 0)
		{
			$serial->sendMessage("8");			
		}
		
		if(strcmp($cmd, " Polso uno indietro ") == 0)
		{
			$serial->sendMessage("9");			
		}
		
		if(strcmp($cmd, " Polso due avanti ") == 0)
		{
			$serial->sendMessage("a");			
		}
		
		if(strcmp($cmd, " Polso due indietro ") == 0)
		{
			$serial->sendMessage("b");			
		}
		
		if(strcmp($cmd, " Mano avanti ") == 0)
		{
			$serial->sendMessage("c");			
		}
		
		if(strcmp($cmd, " Mano indietro ") == 0)
		{
			$serial->sendMessage("d");			
		}
		
		if(strcmp($cmd, " Stop ") == 0)
		{
			$serial->sendMessage("3");			
		}
	}

	if(isset($_POST['home']))
	{
		print("<script> location.href = 'index.php'; </script>");
	}

	$serial->deviceClose();
?>
