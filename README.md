# UART_Driver_Development

# UART-baserad LED-styrning med STM32

Detta projekt syftar till att implementera en UART-kommunikationsprotokoll på en STM32-mikrokontrollerplattform för att styra LED-lampor. 

## Syfte och mål

Syftet med projektet är att demonstrera användningen av UART-protokollet för att kommunicera med en STM32-mikrokontroller och styra LED-lampor. 
Målet är att ge en djupare förståelse för UART-kommunikation och hur man implementerar en pålitlig och effektiv drivrutin för att hantera kommunikationen.

## Projektstruktur
Projektet består av följande filer och mappar:

- `code`: En mapp som innehåller källkoden för projektet.
    - `main.cpp`: Huvudprogrammet som initierar UART-kommunikationen och LED-styrningen.
    - `uart.cpp`: Implementeringen av UART-drivrutinen.
    - `led.cpp`: Implementeringen av LED-drivrutinen.
- `include`: En mapp som innehåller headerfiler för projektet.
    - `uart.h`: Headerfil för UART-drivrutinen.
    - `led.h`: Headerfil för LED-drivrutinen.

## Användning

För att använda projektet behöver du en STM32-mikrokontrollerplattform som stöder UART-kommunikation och LED-lampor. 
Du kan ladda upp koden till mikrokontrollern och ansluta LED-lamporna till de utgångar som specificeras i LED-drivrutinen.

## Begränsningar

Detta projekt är avsett att visa grundläggande funktionalitet för att styra LED-lampor med hjälp av UART-kommunikation på en STM32-mikrokontrollerplattform. 
Det är inte optimerat för prestanda eller energieffektivitet och bör inte användas i produktionssystem utan nödvändiga förbättringar och anpassningar.

