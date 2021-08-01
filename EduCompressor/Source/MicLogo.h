/*
  ==============================================================================

    MicLogo.h
    Created: 25 Jun 2021 11:45:52am
    Author:  Braden Carei

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MicLogo  : public juce::Component
{
public:
    MicLogo();
    ~MicLogo() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MicLogo)
};
