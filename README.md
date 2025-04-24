# senior_design
Team members: Nick Carlton, Joe Liptock, Bob Barnett, Silas Stevens, and Ju Lee. 
Mentor: Michael Goryll. 
TA: Brookelyn Barnes

Because current guitar pedals are expensive, inflexible, or difficult-to-adjust in real-time, we are developing a *low-cost guitar pedal with modular I/O/controls panels and reconfigurable core*.

The code here performs three general tasks:
1) Integrates our modular I/O panels;
2) Integrates our modular controls panels; and
3) Digitally processes input audio stream(s) to produce acoustically pleasing processed signal(s).

To use this code, open the Daisy Seed "Getting Started" tutorial at https://daisy.audio/tutorials/cpp-dev-env/. Complete step 1.

Between step 1 and step 2, locate a folder where you want to clone the repository. On Windows, you can open File Explorer, navigate to your desired destination, then copy the filepath from the address bar. On Mac, I imagine you can do something similar with Finder.

At step 2, replace the command listed in the tutorial with the command below. You should enter this command in your VS Code Git Bash terminal. At the end, append the destination filepath you found above.
```
git clone --recurse-submodules https://github.com/nickccarlton/senior_design.git <FILEPATH>
```

You can flash the DaisySeed with the code cloned using the commands in step 3A of the "Getting Started" tutorial.

Simple review of git commands: https://rogerdudler.github.io/git-guide/.