===========================================================
					CONSOLE APPLICATION
===========================================================
created by: Justin Loveless
created on: 12/19/2015

This project contains an executable file in 
"AidenLabsAlgorithmChallenge\Release". This executable is
intended to be opened from the command line. 

This executable expects to receive a list of bucket_sizes
followed by one target_value. 
It will then return true false:
true - if the buckets can be used to reach the target_value
false - if they cannot

Example execution and result:

AidenLabsAlgorithmChallenge.exe 5 7 8 18
true

in the example above, the bucket_sizes are 5,7, and 8; the
target_value is 18; and it is possible to reach 18 given 
those bucket sizes (5 + 5 + 8).