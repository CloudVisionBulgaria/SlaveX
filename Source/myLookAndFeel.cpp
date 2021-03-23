/*
  ==============================================================================
	Created: 14 Dec 2017 10:16:04am
	Author:  Stefan Remberg
  ==============================================================================
*/

#include "myLookAndFeel.h"


//==============================================================================
myLookAndFeelV3::myLookAndFeelV3()
{
	File knobImageFile2 = File::getSpecialLocation
	(File::SpecialLocationType::userDesktopDirectory).getChildFile("Knobs/knob1.png");
	img2 = ImageCache::getFromFile(knobImageFile2);
}

//==============================================================================
void myLookAndFeelV3::drawRotarySlider(Graphics& g,
	int x, int y, int width, int height, float sliderPos,
	float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	if (img2.isValid())
	{
		const double rotation = (slider.getValue()
			- slider.getMinimum())
			/ (slider.getMaximum()
				- slider.getMinimum());

		const int frames = img2.getHeight() / img2.getWidth();
		const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centerX = x + width * 0.5f;
		const float centerY = y + height * 0.5f;
		const float rx = centerX - radius - 1.0f;
		const float ry = centerY - radius;

		g.drawImage(img2,
			(int)rx,
			(int)ry,
			2 * (int)radius,
			2 * (int)radius,
			0,
			frameId * img2.getWidth(),
			img2.getWidth(),
			img2.getWidth());
	}
	else
	{
		static const float textPpercent = 0.35f;
		Rectangle<float> text_bounds(1.0f + width * (1.0f - textPpercent) / 2.0f,
			0.5f * height, width * textPpercent, 0.5f * height);

		g.setColour(Colours::white);

		g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(),
			Justification::horizontallyCentred | Justification::centred, 1);
	}
}