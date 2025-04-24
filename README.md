# senior_design
Team members: Nick Carlton, Joe Liptock, Bob Barnett, Silas Stevens, and Ju Lee. 
Mentor: Michael Goryll. 
TA: Brookelyn Barnes

Because current guitar pedals are expensive, inflexible, or difficult-to-adjust in real-time, we are developing a *low-cost guitar pedal with modular I/O/controls panels and reconfigurable core*.

The code here performs three general tasks:
1) Integrates our modular I/O panels;
2) Integrates our modular controls panels; and
3) Digitally processes input audio stream(s) to produce acoustically pleasing processed signal(s).

To use this code, first complete step 1, "Install the Toolchain," of the Daisy Seed "Getting Started" tutorial.
https://daisy.audio/tutorials/cpp-dev-env/.

At step 1.5, open Windows Explorer or Finder, and navigate to a folder where you want to clone the repository.

At step 2, replace the command listed with the command below. You should enter this command in your VS Code Git Bash terminal. At the end, add the destination filepath you found in step 1.5.
```
git clone --recurse-submodules https://github.com/nickccarlton/senior_design.git <FILEPATH>
```

You can flash the DaisySeed with the code cloned using the commands in step 3A of the "Getting Started" tutorial.

Simple review of git commands: https://rogerdudler.github.io/git-guide/.