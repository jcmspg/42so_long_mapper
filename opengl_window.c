/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joamiran@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:47:52 by joao              #+#    #+#             */
/*   Updated: 2025/01/01 20:51:09 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapper.h"

int main(void)
{
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "HELLO WORLD", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return -1;
    }

    // make the window's context current
    glfwMakeContextCurrent(window);

    // loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // render here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap front and back buffers
        glfwSwapBuffers(window);

        // poll for and process events
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
