# Password Generator

A simple program that I completed in a couple hours (mainly due to setting up the text files and figuring out the phonetics lol).

It take a random starting consonant, a random vowel, and an ending consonant to make one syllable. It then combines syllables to make a string that is close to the desired length (inputted by stdin). This string can be used as a password, though I'm sure people could find another use for it. Hopefully this improves password strength.

Inspired by https://www.ted.com/talks/lorrie_faith_cranor_what_s_wrong_with_your_pa_w0rd?referrer=playlist-who_are_the_hackers

I realized through this video (mandatory homework for a class that I was taking) that having a strong password that's also easy to remember is important. Most password-generating programs give you a random string of characters, numbers and symbols. While this is much more powerful than the passwords that this program creates, it would be realistically impossible to remember even one of them, and unrealistic for someone to, say, try to tell their friend over the phone. This program makes passwords that are able to be pronounced, and thus probably more memorable, through the syllable-making.

For RNG, I decided to not use the rand() function from cstdlib: https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
and instead used std::random_device which can be non-deterministic.

I also made a blacklist of words that should not be chosen, taken from https://www.cs.cmu.edu/~biglou/resources/bad-words.txt
