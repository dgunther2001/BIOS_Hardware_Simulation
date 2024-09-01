This is my project that simulates a very basic computer boot process. <br />

As of now, the following processes occur: <br />
&emsp; 1. Hardware tests to ensure that my software abstractions of logic gates and d-latches work. <br />
&emsp; 2. A "voltage" that is slightly randomized to illustrate the analog nature of electrical signals <br />
&emsp;    is sent and validated (would be done with comparators, which I may implement later) <br />
&emsp;    to a gated d-latch (power latch), which is SET. <br />
&emsp; 3. Although the electronics are slightly abstracted away, a digital signal is sent to the CPU <br />
&emsp;    (presumably by the power latch). The CPU validates the signal strength (again, comparators) <br />
&emsp;    and the program counter, which is just a memory cell of 4 d-latches are all reset to 0 (0x0).  <br />
&emsp; 4. For the next stage, we will have the CPU begin fetching from ROM, which will live at 0x0 (pc value) <br />
&emsp;    and begin a power on self test (POST). <br />

To run it in bash/zsh, run the command: <br />
&emsp; => ./startup.sh <br />

To run it through a UNIX cmd line: <br />
&emsp; => docker build -t bios . <br />
&emsp; => docker run --rm bios <br />
