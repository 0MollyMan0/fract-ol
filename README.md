# Fract-ol

## The purpose

The purpose of this project is to create a program the represent different fractals (Mandelbrot, Julia and Burning Ship) in real time.

## How to use

### Compilation

For the compilation because of the Makefile you just have to do:

```bash
make
```

This will compile all the necessary files. If the project is compile and you still decide to run this command this will compile only the files that was deleted or modified one's.

```bash
make clean
```

This will deleted all .o files that aren't necessary when the executable is already compile.

```bash
make fclean
```
This will delete .o files and the executable

```bash
make re
```
This will execute the `make fclean` and `make` command.

### How to launch

To launch the program you'll have to call the executable.

```bash
./fractol
```
Next you choose the fractal you want to see (not that important you'll see why), you can choose between `mandelbrot`, `julia`, and `burning_ship`.

If you choose `julia` you'll have to add 2 more parameters, the real and imaginary number (x1000) that represent the complex number that will be added in the function.

Example:
```bash
./fractol julia 230 675
```
This represent z = z² + (0.23 + 0.675i).

### In the program

When you in you can move (up down left right) with WASD or directional arrow as you wish.

You also move by zooming with the mouse scroll (it will follow the mouse pointer).

You can change color palette with 1 and 2 (have fun with it).

You can change the julia complex number you enter as parameters at the start, by using z to decrease the real number, x to increase the real number, c to decrease the imaginary number, v to increase the imaginary number.

Do you remember when i say that choosing the fractal at the start is not that important ? It's because you can switch between fractal by using 3 and 4 !!


## Resources

[Fractals are typically not self-similar - 3Blue1Brown](https://youtu.be/gB9n2gHsHN4?si=Ra92GTBT2gWyFKkY)

[Comment Générer des Fractales ? ❄️ - DIMENSION CODE](https://youtu.be/wUlVFYJIUNA?si=ULHwyRXmi1jczMzw)

[Fractale - Wikipedia](https://fr.wikipedia.org/wiki/Fractale)
