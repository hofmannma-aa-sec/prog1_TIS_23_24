#!/bin/bash
echo "C oder C++"
read auswahl

if [ $auswahl == 'C' ] 
then
	echo "Datei und Pfad der C-Datei"

elif [ $auswahl == 'C++' ]
then
	echo "Datei und Pfad der C++-Datei"
else
	echo "Error"
fi

