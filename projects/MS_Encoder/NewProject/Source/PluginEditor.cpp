/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    encode.setSize(50., 50.);

    addAndMakeVisible(&encode);

    encode.addListener(this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("M/S encode decode", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    encode.setBounds(getWidth() / 2., getHeight() / 2., 50, 50);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::buttonStateChanged(juce::Button* button)
{
    audioProcessor.encode = encode.getToggleState();
}

void NewProjectAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    audioProcessor.encode = encode.getToggleState();
}
