This is my project that simulates a very basic computer boot process.

As of now, the following processes occur:

1. Hardware tests to ensure that my software abstractions of logic gates and d-latches work.  
2. A "voltage" that is slightly randomized to illustrate the analog nature of electrical signals  
   is sent and validated (would be done with comparators, which I may implement later)  
   to a gated d-latch (power latch), which is SET.  
3. Although the electronics are slightly abstracted away, a digital signal is sent to the CPU  
   (presumably by the power latch). The CPU validates the signal strength (again, comparators)  
   and the program counter, which is just a memory cell of 4 d-latches are all reset to 0 (0x0).  
4. For the next stage, we will have the CPU begin fetching from ROM, which will live at 0x0 (pc value)  
   and begin a power on self test (POST).  

To run it in bash/zsh, run the command:  
&nbsp; => `./startup.sh`

To run it through a non-UNIX cmd line:  
&nbsp; => `docker build -t bios .`  
&nbsp; => `docker run --rm bios`
