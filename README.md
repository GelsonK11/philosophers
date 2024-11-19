# Philosophers 🧠🍴

A project inspired by the classic **Dining Philosophers Problem**, part of the 42 curriculum. This project explores advanced concepts of **threads**, **mutexes**, and **synchronization** in multithreaded programming.

## Table of Contents

- [About the Project](#about-the-project)
- [How It Works](#how-it-works)
- [How to Use](#how-to-use)
- [Project Structure](#project-structure)
- [Execution Examples](#execution-examples)
- [What I Learned](#what-i-learned)
- [License](#license)

## About the Project

The *Philosophers* project challenges you to simulate a group of philosophers sitting at a table, alternating between thinking, eating, and sleeping, all while avoiding **deadlocks** and **race conditions**.

### Rules

1. Each philosopher alternates between **thinking**, **eating**, and **sleeping**.
2. To eat, a philosopher must pick up two forks (mutexes).
3. The program must handle edge cases, such as philosophers "dying" due to starvation or resource blocking.

## How It Works

This implementation includes:
- **Threads** to represent philosophers.
- **Mutexes** to manage fork access.
- **Synchronization mechanisms** to prevent issues like **deadlocks** and **race conditions**.

## How to Use

### Requirements

- GCC or Clang compiler.
- POSIX-compliant system (Linux or macOS).

### Steps to Compile and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/GelsonK11/philosophers.git
   cd philosophers


2. Compile the project:
make

3. Run the program:
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_meals]
Example
Simulate 5 philosophers with the following parameters:

Time to die: 800ms
Time to eat: 200ms
Time to sleep: 200ms
bash
Copiar código
./philo 5 800 200 200


Project Structure
philosophers/
├── Makefile                # Compilation script
├── main.c                  # Entry point of the program (starting point)
├── ft_pthreads.c           # Thread management functions
├── ft_philo_life.c         # Main logic of philosopher's life cycle (eating, thinking, sleeping)
├── ft_utils.c              # Utility functions (e.g., ft_usleep, time functions)
├── ft_init_program.c       # Initialization of the program and philosophers
├── ft_actions.c            # Functions for actions like eating, thinking, sleeping
├── includes/               # Header files
│   ├── philosophers.h      # Main header file containing function prototypes and structures
│   └── ft_pthreads.h       # Header for thread-related functions (optional, if needed)
├── README.md               # Project documentation



Conclusion
Thank you for exploring this project! 🎉 I hope you found it insightful, whether you’re learning about concurrency, synchronization, or multithreading in C. The Philosophers project helped me gain a deeper understanding of these concepts and their practical applications.

Feel free to fork this repository, contribute to it, or simply use it as a reference in your own projects.

Happy coding! 🚀
