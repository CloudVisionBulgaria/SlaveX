/*
  ==============================================================================

	PluginProcessor.cpp
	Created: 23 Mar 2021 9:09:06pm
	Author:  bobkata

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "PingPongDelay.h"

void SlaveXAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midi) {

	const int numSamples = buffer.getNumSamples();

	const int totalNumInputChannels = getTotalNumInputChannels();
	const int totalNumOutputChannels = getTotalNumOutputChannels();

	// clear any output channels that didn't contain input data
	for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());


	PingPongDelay pingPongDelay;
	// pingPongDelay.ApplyEffect(buffer);

}


AudioProcessorEditor* SlaveXAudioProcessor::createEditor()
{
	return new SlaveXAudioProcessorEditor(*this);
}