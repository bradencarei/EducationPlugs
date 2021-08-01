/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
EduCompressorAudioProcessorEditor::EduCompressorAudioProcessorEditor (EduCompressorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 500);
    startTimer(60);
    input.addListener(this);
    input.setLookAndFeel(&Knob);
    input.setBounds(102.5, 300, 75, 75);
    input.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    input.setRange(0.f, 4.f,0.01f);
    input.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(input);
    
    ratio.addListener(this);
    ratio.setLookAndFeel(&Knob);
    ratio.setBounds(242.5, 300, 75, 75);
    ratio.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    ratio.setRange(0.f, 4.f,0.01f);
    ratio.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(ratio);
    
    thresh.addListener(this);
    thresh.setLookAndFeel(&Knob);
    thresh.setBounds(382.5, 300, 75, 75);
    thresh.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    thresh.setRange(0.f, 4.f,0.01f);
    thresh.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(thresh);
    
    makeup.addListener(this);
    makeup.setLookAndFeel(&Knob);
    makeup.setBounds(522.5, 300, 75, 75);
    makeup.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    makeup.setRange(0.f, 4.f,0.01f);
    makeup.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(makeup);
    
    attack.addListener(this);
    attack.setLookAndFeel(&Knob);
    attack.setBounds(102.5, 410, 75, 75);
    attack.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    attack.setRange(0.f, 4.f,0.01f);
    attack.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(attack);
    
    release.addListener(this);
    release.setLookAndFeel(&Knob);
    release.setBounds(242.5, 410, 75, 75);
    release.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    release.setRange(0.f, 4.f,0.01f);
    release.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(release);
    
    knee.addListener(this);
    knee.setLookAndFeel(&Knob);
    knee.setBounds(382.5, 410, 75, 75);
    knee.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    knee.setRange(0.f, 4.f,0.01f);
    knee.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(knee);
    
    mix.addListener(this);
    mix.setLookAndFeel(&Knob);
    mix.setBounds(522.5, 410, 75, 75);
    mix.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mix.setRange(0.f, 4.f,0.01f);
    mix.setTextBoxStyle(juce::Slider::NoTextBox, false, 75, 25);
    addAndMakeVisible(mix);
    
    inputButton.addListener(this);
    inputButton.setBounds(102.5,265,75,30);
    inputButton.setButtonText("Input");
    inputButton.setColour(0x1000100, juce::Colours::deepskyblue);
    inputButton.setToggleState(false, juce::dontSendNotification);
    inputButton.toBack();
    addAndMakeVisible(inputButton);
    
    ratioButton.addListener(this);
    ratioButton.setBounds(242.5,265,75,30);
    ratioButton.setButtonText("Ratio");
    ratioButton.setColour(0x1000100, juce::Colours::deepskyblue);
    ratioButton.setToggleState(false, juce::dontSendNotification);
    ratioButton.toBack();
    addAndMakeVisible(ratioButton);
    
    threshButton.addListener(this);
    threshButton.setBounds(382.5,265,75,30);
    threshButton.setButtonText("Threshold");
    threshButton.setColour(0x1000100, juce::Colours::deepskyblue);
    threshButton.setToggleState(false, juce::dontSendNotification);
    threshButton.toBack();
    addAndMakeVisible(threshButton);
    
    makeupButton.addListener(this);
    makeupButton.setBounds(522.5,265,75,30);
    makeupButton.setButtonText("Makeup");
    makeupButton.setColour(0x1000100, juce::Colours::deepskyblue);
    makeupButton.setToggleState(false, juce::dontSendNotification);
    makeupButton.toBack();
    addAndMakeVisible(makeupButton);
    
    attackButton.addListener(this);
    attackButton.setBounds(102.5,375,75,30);
    attackButton.setButtonText("Attack");
    attackButton.setColour(0x1000100, juce::Colours::deepskyblue);
    attackButton.setToggleState(false, juce::dontSendNotification);
    attackButton.toBack();
    addAndMakeVisible(attackButton);
    
    releaseButton.addListener(this);
    releaseButton.setBounds(242.5,375,75,30);
    releaseButton.setButtonText("Release");
    releaseButton.setColour(0x1000100, juce::Colours::deepskyblue);
    releaseButton.setToggleState(false, juce::dontSendNotification);
    releaseButton.toBack();
    addAndMakeVisible(releaseButton);
    
    kneeButton.addListener(this);
    kneeButton.setBounds(382.5,375,75,30);
    kneeButton.setButtonText("Knee");
    kneeButton.setColour(0x1000100, juce::Colours::deepskyblue);
    kneeButton.setToggleState(false, juce::dontSendNotification);
    kneeButton.toBack();
    addAndMakeVisible(kneeButton);
    
    mixButton.addListener(this);
    mixButton.setBounds(522.5,375,75,30);
    mixButton.setButtonText("Mix");
    mixButton.setColour(0x1000100, juce::Colours::deepskyblue);
    mixButton.setToggleState(false, juce::dontSendNotification);
    mixButton.toBack();
    addAndMakeVisible(mixButton);
   
    
        
    

}

EduCompressorAudioProcessorEditor::~EduCompressorAudioProcessorEditor()
{
    
}

//==============================================================================
void EduCompressorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.drawImage(pb, 0, 0, 700, 500, 0, 0, 700, 500);
    
    g.setColour (juce::Colours::black);
    g.setFont (12.0f);
    
    
    
    g.drawImage(mb, 100, -75, 500, 500, 0, 0, 799, 799);
    
    //g.drawImage(mic, 15, 50, micSize, micSize, 0, 0, 799, 799);
    
    
    microphone.setImage(mic);
    bubble.setImage(tb);
    attackFact.setImage(aFact);
    
    microphone.setBounds(15, 50, micSize, micSize);
    addAndMakeVisible(microphone);
    
    if(micSize < 400 && buttonBool == true)
        micSize = micSize*1.1;
    else if(buttonBool==true && micSize >= 400){
        bubble.setBounds(260, 40, 400, 400);
        addAndMakeVisible(bubble);
        attackFact.setBounds(405, 115, 180, 210);
        addAndMakeVisible(attackFact);
    }
    
}

void EduCompressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void EduCompressorAudioProcessorEditor::timerCallback()
{
    repaint();
}

void EduCompressorAudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    
}

void EduCompressorAudioProcessorEditor::buttonClicked(juce::Button * button)
{
    if(button == &attackButton)
    {
        buttonBool = true;
    }
}
