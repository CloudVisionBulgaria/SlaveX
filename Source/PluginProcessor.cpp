/*
  ==============================================================================

	PluginProcessor.cpp
	Created: 23 Mar 2021 9:09:06pm
	Author:  bobkata

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
/**
	The constructor.
	Before initializing the values, the constructor is initializing the input and output channels using an initializer list.
	Since this is an effect plugin, we have a single input and a single output bus.
*/
SlaveXAudioProcessor::SlaveXAudioProcessor(AudioProcessor(BusesProperties().withOutput("Output", AudioChannelSet::stereo(), true)))
{

}

//==============================================================================
bool SlaveXAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SlaveXAudioProcessor::createEditor()
{
	return new SlaveXAudioProcessorEditor(*this);
}
