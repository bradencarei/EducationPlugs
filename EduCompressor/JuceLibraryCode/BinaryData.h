/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   attckFact_png;
    const int            attckFact_pngSize = 71770;

    extern const char*   thotBubble_png;
    const int            thotBubble_pngSize = 11513;

    extern const char*   plugBack_jpeg;
    const int            plugBack_jpegSize = 358733;

    extern const char*   meter_back_png;
    const int            meter_back_pngSize = 248452;

    extern const char*   micGraphic_png;
    const int            micGraphic_pngSize = 87939;

    extern const char*   Knob_png;
    const int            Knob_pngSize = 10787;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 6;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
