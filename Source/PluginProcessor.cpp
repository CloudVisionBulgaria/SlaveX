/*
  ==============================================================================

	PluginProcessor.cpp
	Created: 23 Mar 2021 9:09:06pm
	Author:  bobkata

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


void SlaveXAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midi) {
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());



}


AudioProcessorEditor* SlaveXAudioProcessor::createEditor()
{
	return new SlaveXAudioProcessorEditor(*this);
}