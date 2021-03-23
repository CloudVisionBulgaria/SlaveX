/*
  ==============================================================================

	PluginProcessor.h
	Created: 23 Mar 2021 9:05:30pm
	Author:  bobkata

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SlaveXAudioProcessor : public AudioProcessor
{
public:
	SlaveXAudioProcessor() : AudioProcessor(BusesProperties()
		.withInput("Input", AudioChannelSet::stereo())
		.withOutput("Output", AudioChannelSet::stereo())
		.withInput("Sidechain", AudioChannelSet::stereo()))
	{
		//addParameter(filter_band_size = new AudioParameterFloat("filter_band_size", "Filter Band Size (Octaves):", 0.25f, 10.0f, 1.0f));
	}

	~SlaveXAudioProcessor() {}

	//==============================================================================
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override
	{
		// the sidechain can take any layout, the main bus needs to be the same on the input and output
		return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet()
			&& !layouts.getMainInputChannelSet().isDisabled();
	}

	//==============================================================================
	void prepareToPlay(double, int) override {}
	void releaseResources() override {}

	void processBlock(AudioBuffer<float>& buffer, MidiBuffer&) override;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override { return true; }
	const String getName() const override { return "SlaveX"; }
	bool acceptsMidi() const override { return false; }
	bool producesMidi() const override { return false; }
	double getTailLengthSeconds() const override { return 0.0; }
	int getNumPrograms() override { return 1; }
	int getCurrentProgram() override { return 0; }
	void setCurrentProgram(int) override {}
	const String getProgramName(int) override { return {}; }
	void changeProgramName(int, const String&) override {}
	bool isVST2() const noexcept { return (wrapperType == wrapperType_VST); }

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override
	{
		MemoryOutputStream stream(destData, true);
	}

	void setStateInformation(const void* data, int sizeInBytes) override
	{
		MemoryInputStream stream(data, static_cast<size_t> (sizeInBytes), false);
	}

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SlaveXAudioProcessor)
};