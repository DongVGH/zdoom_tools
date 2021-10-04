# zdoom_tools
Some tools useful for ZDoom-related project development


# MD3 to Modeldef
**md3toframeindex input [base sprite name]**

Input is the input MD3's filename, and base sprite name is an optional sprite name to use. It's 3 characters long, and the last character is a digit from 0 to 9 (so if the input model has 260 frames, the most supported by this tool, the range of frames is MDL0 A to MDL9 Z), if not specified, MDL will be used instead.

Output file is a txt with the same name as the input md3.
