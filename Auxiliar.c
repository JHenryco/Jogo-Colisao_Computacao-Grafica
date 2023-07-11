#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define WINDOW_WIDTH 660
#define WINDOW_HEIGHT 600
#define CAR_WIDTH 60
#define CAR_HEIGHT 120
#define OBJECT_WIDTH 40
#define OBJECT_HEIGHT 40
#define LANE_WIDTH 200
#define LANE_HEIGHT 800
#define LANE_SPACING 30
#define MAX_OBJECTS 2

int carLane;
int carX;
int score;
bool gameover;
bool instructionsDisplayed;
bool gameStarted;
float objectSpeed = 5.0;
float centerLineOffset = 0.0;

typedef struct {
    int x;
    int y;
    int lane;
    bool active;
} Object;

Object objects[MAX_OBJECTS];

void drawCar() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(carX, 20);
    glVertex2f(carX + CAR_WIDTH, 20);
    glVertex2f(carX + CAR_WIDTH, 20 + CAR_HEIGHT);
    glVertex2f(carX, 20 + CAR_HEIGHT);
    glEnd();
}

void drawObject(int index) {
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(objects[index].x, objects[index].y);
    glVertex2f(objects[index].x + OBJECT_WIDTH, objects[index].y);
    glVertex2f(objects[index].x + OBJECT_WIDTH, objects[index].y + OBJECT_HEIGHT);
    glVertex2f(objects[index].x, objects[index].y + OBJECT_HEIGHT);
    glEnd();
}

void drawLanes() {
    glColor3f(0.5, 0.5, 0.5);
    int i;
    for (i = 0; i < 3; i++) {
        glBegin(GL_QUADS);
        glVertex2f(i * (LANE_WIDTH + LANE_SPACING), 0);
        glVertex2f(i * (LANE_WIDTH + LANE_SPACING) + LANE_WIDTH, 0);
        glVertex2f(i * (LANE_WIDTH + LANE_SPACING) + LANE_WIDTH, LANE_HEIGHT);
        glVertex2f(i * (LANE_WIDTH + LANE_SPACING), LANE_HEIGHT);
        glEnd();
    }
}

void drawCenterLines() {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glEnable(GL_LINE_SMOOTH);

    // Defina o comprimento dos segmentos de linha e dos espaços vazios
    float lineSegmentLength = 80.0;
    float spaceSegmentLength = 200.0;

    int i;
    for (i = 0; i < 3; i++) {
        int laneX = i * (LANE_WIDTH + LANE_SPACING) + LANE_WIDTH / 2;

        // Desenhe as linhas descontínuas
        float currentPosition = centerLineOffset;
        while (currentPosition < WINDOW_HEIGHT) {
            // Desenhe um segmento de linha
            glBegin(GL_LINES);
            glVertex2f(laneX, currentPosition);
            glVertex2f(laneX, currentPosition + lineSegmentLength);
            glEnd();

            // Atualize a posição atual para o próximo espaço vazio
            currentPosition += lineSegmentLength + spaceSegmentLength;
        }
    }

    glDisable(GL_LINE_SMOOTH);
}

void drawScore() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(10, WINDOW_HEIGHT - 20);
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    int length = strlen(scoreText);
    int i;
    for (i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scoreText[i]);
    }
}

void drawGameOver() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - 80, WINDOW_HEIGHT / 2);
    char gameOverText[20] = "Game Over";
    int length = strlen(gameOverText);
    int i;
    for (i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameOverText[i]);
    }
    glRasterPos2f(WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2 - 30);
    gameOverText[20];
    sprintf(gameOverText, "Score: %d", score);
    length = strlen(gameOverText);
    for (i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameOverText[i]);
    }
}

void drawInstructions() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - 120, WINDOW_HEIGHT / 2);
    char instructionsText[200] = "Instructions:\n\nUse the left and right arrow keys to move the car.\nAvoid colliding with the green objects.\nScore points by passing the objects.";
    int length = strlen(instructionsText);
    int i;
    for (i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, instructionsText[i]);
    }
}

void update(int value) {
    if (!gameover && gameStarted) {
        // Update the objects
        int i;
        for (i = 0; i < MAX_OBJECTS; i++) {
            Object *object = &objects[i];
            if (object->active) {
                object->y -= objectSpeed; //velocidade dos objetos

                // Check for collision
                if (object->x < carX + CAR_WIDTH &&
                    object->x + OBJECT_WIDTH > carX &&
                    object->y < 20 + CAR_HEIGHT &&
                    object->y + OBJECT_HEIGHT > 20) {
                    gameover = true;
                    break;
                }

                // Check if object is off the screen
                if (object->y < -OBJECT_HEIGHT) {
                    object->active = false;
                    score++;
                }
            }
        }
        if (!(score % 8)) {
            objectSpeed += 0.05; //Aumenta a veocidade ao poucos
            //centerLineOffset -= objectSpeed;
        }
        centerLineOffset -= objectSpeed;

        // Generate new objects
        for (i = 0; i < MAX_OBJECTS; i++) {
            if (!objects[i].active) {
                int randomLane = rand() % 3;

                // Check if lane is occupied
                bool laneOccupied = false;
                int j;
                for (j = 0; j < MAX_OBJECTS; j++) {
                    if (objects[j].active && objects[j].lane == randomLane) {
                        laneOccupied = true;
                        break;
                    }
                }

                // If lane is occupied, find an available lane
                if (laneOccupied) {
                    randomLane = (randomLane + 1) % 3; // Move to the next lane
                    while (randomLane != objects[i].lane) {
                        laneOccupied = false;
                        for (j = 0; j < MAX_OBJECTS; j++) {
                            if (objects[j].active && objects[j].lane == randomLane) {
                                laneOccupied = true;
                                break;
                            }
                        }
                        if (!laneOccupied) {
                            break;
                        }
                        randomLane = (randomLane + 1) % 3; // Move to the next lane
                    }
                }

                objects[i].active = true;
                objects[i].x = randomLane * (LANE_WIDTH + LANE_SPACING) + (LANE_WIDTH - OBJECT_WIDTH) / 2;
                objects[i].y = WINDOW_HEIGHT;
                objects[i].lane = randomLane;
                break;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (!gameover && gameStarted) {
        //centerLineOffset -= objectSpeed;
        drawLanes();
        drawCenterLines();
        int i;
        for (i = 0; i < MAX_OBJECTS; i++) {
            if (objects[i].active) {
                drawObject(i);
            }
        }
        drawCar();
        drawScore();
    }
	if (gameover) {
        drawGameOver();
    }
	if (instructionsDisplayed) {
        drawInstructions();
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeyboard(int key, int x, int y) {
    if (!instructionsDisplayed && gameStarted) {
        switch (key) {
            case GLUT_KEY_LEFT:
                if (carLane > 0)
                    carLane--;
                break;
            case GLUT_KEY_RIGHT:
                if (carLane < 2)
                    carLane++;
                break;
        }

        carX = carLane * (LANE_WIDTH + LANE_SPACING) + (LANE_WIDTH - CAR_WIDTH) / 2;
    }
}

void menu(int choice) {
    switch (choice) {
        case 1:
            gameStarted = true;
            gameover = false;
            instructionsDisplayed = false;
            score = 0;
            objectSpeed = 5.0;
            centerLineOffset = 0.0;
            int i;
            for (i = 0; i < MAX_OBJECTS; i++) {
                objects[i].active = false;
            }
            break;
        case 2:
            instructionsDisplayed = true;
            gameStarted = false;
            gameover = false;
            break;
    }
}

void createMenu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Iniciar Jogo", 1);
    glutAddMenuEntry("Instruções", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    srand(time(NULL));

    carLane = 1;
    carX = carLane * (LANE_WIDTH + LANE_SPACING) + (LANE_WIDTH - CAR_WIDTH) / 2;
    score = 0;
    gameover = false;
    instructionsDisplayed = false;
    gameStarted = false;

    int i;
    for (i = 0; i < MAX_OBJECTS; i++) {
        objects[i].active = false;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Car Game");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeyboard);
    glutTimerFunc(0, update, 0);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    createMenu();

    glutMainLoop();
    return 0;
}
