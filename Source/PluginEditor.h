/*
  ==============================================================================

	PluginEditor.h
	Created: 23 Mar 2021 9:15:30pm
	Author:  bobkata

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"
#include "myLookAndFeel.h"

//==============================================================================
/**
This is my look and feel class where I draw my knob design.
*/
class SlaveXLookAndFeel : public LookAndFeel_V4
{

};

class SlaveXAudioProcessorEditor : public AudioProcessorEditor,
	public Slider::Listener
{
public:
	SlaveXAudioProcessorEditor(SlaveXAudioProcessor&);
	~SlaveXAudioProcessorEditor();

	//==============================================================================
	void paint(Graphics&) override;
	void resized() override;

	SlaveXLookAndFeel slaveXFeel; //Instance for my look and feel class.

	myLookAndFeelV3 myLookAndFeelV3;

	//My sliders and labels.
	Slider drySlider;
	Label dryLabel;
	Slider wetSlider;
	Label wetLabel;
	Slider volumeSlider;
	Label volumeLabel;
	Slider feedbackSlider;
	Label feedbackLabel;
	Slider timeSlider;
	Label timeLabel;

	void sliderValueChanged(Slider* slider) override; //Method from SliderListener. Listens for value changes.

	//Smart pointers for slider attachments which will connect sliders with parameters and change them acoordingly.
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> volumeAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> dryAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> wetAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> feedAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> timeAttach;

private:
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SlaveXAudioProcessor& processor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SlaveXAudioProcessorEditor)
};