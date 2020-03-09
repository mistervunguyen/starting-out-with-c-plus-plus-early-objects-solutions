// Chapter 4 - Programming Challenge 20, Spectral Analysis
// This program determines radiation type based on its electromagnectic wavelength.
#include <iostream>
using namespace std;

int main()
{
	double waveLength;       // Wave length in meters

	// Input the wave length
	cout << "Enter the radiation's wavelength in meters: ";
	cin  >> waveLength;

	// Determine radiation type from wavelength and display result
	if (waveLength <= 1e-11)
		cout << "That is a gamma ray.\n";
	else if (waveLength <= 1e-8)
		cout << "That is an x-ray.\n";
	else if (waveLength <= 4e-7)
		cout << "That is ultraviolet light.\n";
	else if (waveLength <= 7e-7)
		cout << "That is visible light.\n";
	else if (waveLength <= 1e-3)
		cout << "That is infrared light.\n";
	else if (waveLength <= 1e-2)
		cout << "That is a microwave.\n";
	else
		cout << "That is a radio wave.\n";

	return 0;
}

/* SAMPLE RUN OUTPUT

Enter the radiation's wavelength in meters: 3e-5
That is infrared light.
*/
