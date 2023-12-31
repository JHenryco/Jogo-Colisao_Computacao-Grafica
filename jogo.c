#include <GL/glut.h>
#include <random>
#include <string>
#include <iostream>
#include <cmath>

//Dimensões dos objetos
float peixeWidth = 1.0f;    //Largura do Peixe
float peixeHeight = 1.0f;    //Altura do Peixe
float peixeX = 3.0f;    //Posição Inicial X do Peixe
float peixeY = 10.0f;    //Posição Inicial Y do Peixe

float minhocaWidth = 0.5f;    //Largura da Minhoca
float minhocaHeight = 0.5f;    //Altura da Minhoca
float minhocaX = 40.0f;    //Posição Inicial X da Minhoca
float minhocaY = 10.0f;    //Posição Inicial Y da Minhoca

float barreiraWidth = 1.5f;    //Largura da Barreira
float barreiraHeight = 7.5f;    //Altura da Barreira
float barreiraX = -2.0f;    //Posição Inicial X da Barreira
float barreiraY = 10.0f;    //Posição Inicial Y da Barreira

int pontuacao = 0; // Pontuação do jogo

//Variaveis de apresentação de frames
int tempo = 0;  //Variavel que vai contar os ticks do jogo (+1 a cada 16ms)
int tempo2 = 0; //Variavel que vai contar os ticks lentos do jogo (+1 a cada 16ms)

//Variaveis do mouse
int mouseX = 0;
int mouseY = 0;
bool mouseClicked = false;

//Variavel do gameover
bool isGameOver = false;
bool isPaused = false;

//Ambiente Background
float bolhasX = 30.0f;    //Posição Inicial X das bolhas
float bolhasY = 0.0f;    //Posição Inicial Y das bolhas
float objeto1X = 40.0f;    //Posição Inicial X do objeto de fundo pequeno
float objeto1Y = 2.0f;    //Posição Inicial Y do objeto de fundo pequeno
float objeto2X = 40.0f;    //Posição Inicial X do objeto de fundo médio
float objeto2Y = 15.0f;    //Posição Inicial Y do objeto de fundo médio
float objeto3X = 40.0f;    //Posição Inicial X do objeto de fundo grande
float objeto3Y = 7.0f;    //Posição Inicial Y do objeto de fundo grande

//Background
void drawAmbiente(){
    //Luz ambiente
    //Luz 1
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.5, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 2
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.45, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 3
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.40, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 4
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.35, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 5
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.30, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 6
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.25, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 7
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.20, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 8
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.15, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 9
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.10, 50, 10);
    glPopMatrix();
    glEnd();
    //Luz 10
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(0.0f, 1.0f, 1.0f, 0.005f); // Cor com transparência
    glTranslatef(0.0f, 20.0f, 0.0f);
    glScalef(100.0f, 60.0f, 1.0f);
    glutSolidSphere(0.05, 50, 10);
    glPopMatrix();
    glEnd();


    //Feixes de luz triangular
    //Feixe 1
    GLfloat vertices1[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        3.0f, 0.0f, // vértice 2
        9.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices1[i], vertices1[i + 1]);
    }
    glEnd();
    //Feixe 2
    GLfloat vertices2[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        20.0f, 0.0f, // vértice 2
        25.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices2[i], vertices2[i + 1]);
    }
    glEnd();

    //Feixe 2.1
    GLfloat vertices21[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        12.0f, 0.0f, // vértice 2
        14.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices21[i], vertices21[i + 1]);
    }
    glEnd();

    //Feixe 3
    GLfloat vertices3[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        30.0f, 0.0f, // vértice 2
        38.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices3[i], vertices3[i + 1]);
    }
    glEnd();

    //Feixe 4
    GLfloat vertices4[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        42.0f, 0.0f, // vértice 2
        45.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices4[i], vertices4[i + 1]);
    }
    glEnd();

    //Feixe 5
    GLfloat vertices5[] = {
        -5.0f, 30.0f,  // vértice 1 (centro)
        60.0f, 0.0f, // vértice 2
        80.0f, 0.0f  // vértice 3
    };

    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending

    glColor4f(1.0f, 1.0f, 1.0f, 0.012f); // Cor com transparência

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices5[i], vertices5[i + 1]);
    }
    glEnd();
}

//Background
void drawBolhas(){

    if (tempo2<=30) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(-4.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else if (tempo2>=70) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(4.4f, 0.2f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(1.7f, -0.7f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }

    if (tempo2<=30) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(7.0f, -5.0f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else if (tempo2>=70) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(1.4f, 3.2f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(-3.2f, 3.7f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }

    if (tempo2<=30) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(12.0f, -5.0f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else if (tempo2>=70) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(-17.4f, -8.2f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(9.2f, 7.7f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }

    if (tempo2<=30) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(1.0f, -2.0f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else if (tempo2>=70) {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(-1.4f, 4.2f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else {//0 ~ 80ms frame 1
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(-4.2f, 2.7f, 0.0f); // Posição do corpo
    glScalef(1.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
}

//Background
void drawFundoPerto(){
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.015f); // Cor com transparência
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(5.0f, 5.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    glEnd();
}

//Background
void drawFundoMedio(){
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.015f); // Cor com transparência
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(30.0f, 30.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    glEnd();
}

//Background
void drawFundoLonge(){
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.015f); // Cor com transparência
    glTranslatef(-4.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(70.0f, 70.0f, 1.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    glEnd();
}




//Criação do Peixe
void drawPeixe() {


    if (tempo<=5) { //0 ~ 80ms frame 1
        // Desenhar o corpo do peixe
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.4f, 1.0f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.3f, 0.9f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();


        // Desenhar o olho do peixe (círculo achatado)
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f); // Cor do olho
        glTranslatef(0.6f, 0.2f, 0.4f); // Posição do olho
        glScalef(0.2f, 0.2f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 10, 10); // Desenhar o olho
        glPopMatrix();
    }

    else{//80~160ms = frame 2

        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.1f, 1.1f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();

        // Desenhar o corpo do peixe
        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.0f, 1.0f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();




        // Desenhar o olho do peixe (círculo achatado)
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f); // Cor do olho
        glTranslatef(0.6f, 0.2f, 0.4f); // Posição do olho
        glScalef(0.2f, 0.2f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 10, 10); // Desenhar o olho
        glPopMatrix();
    }

        //Rabo desenhado por dois triangulos
        //Triangulo superior
        GLfloat vertices1[] = {
            -0.7f, 0.0f,  // vértice 1 (centro)
            -1.6f, 0.6f, // vértice 2
            -1.3f, 0.0f  // vértice 3
        };
        glColor3f(0.0f, 0.5f, 1.0f); // Cor da cauda
        // Desenha o triangulo
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 6; i += 2) {
            glVertex2f(vertices1[i], vertices1[i + 1]);
        }

        //Triangulo inferior
        GLfloat vertices2[] = {
            -0.7f, 0.0f,  // vértice 1 (centro)
            -1.6f, -0.6f, // vértice 2
            -1.3f, 0.0f  // vértice 3
        };
        glColor3f(0.0f, 0.5f, 1.0f); // Cor da cauda
        // Desenha o triangulo
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 6; i += 2) {
            glVertex2f(vertices2[i], vertices2[i + 1]);
        }

        glEnd();
}

//Criação da Minhoca
void drawMinhoca() {

    if (tempo>=5) {//0 ~ 80ms frame 1
    //Borda
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(4.1f, 2.1f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();

    //Corpo
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 1.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(4.0f, 2.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
    else{//80 ~ 160ms frame 2
    //Borda
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(5.1f, 1.1f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();

    //Corpo
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 1.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(5.0f, 1.0f, 0.0f); // Escala do corpo
    glutSolidSphere(0.1, 50, 10); // Desenhar o corpo
    glPopMatrix();
    }
}

//Criação da Barreira
void drawBarreira() {

            //Chifre
        float radius = 1.7f; // Raio da semicircunferência
        int numSegments = 100; // Número de segmentos da semicircunferência
        float angleStep = M_PI / numSegments; // Ângulo entre cada segmento

        // Define a cor da borda da semicircunferência (por exemplo, amarelo)
        glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo

        // Define a espessura da borda da semicircunferência (por exemplo, 3.0)
        float lineWidth = 3.0f;

        // Define a posição da semicircunferência
        float xPosition = -1.55f;
        float yPosition = 2.6f;

        // Aumenta a espessura da linha
        glLineWidth(lineWidth);

        // Desenha a parte superior da borda da semicircunferência com a posição definida
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= numSegments; ++i) {
            float angle = angleStep * static_cast<float>(i);
            float x = xPosition + radius * cos(angle);
            float y = yPosition + radius * sin(angle);

            // Verifica se o ponto está acima do eixo x (parte superior)
            if (y >= yPosition) {
                glVertex2f(x, y);
            }
        }
        glEnd();

        //Rabo desenhado por dois triangulos
        //Triangulo superior
        GLfloat vertices1[] = {
            2.0f, 0.0f,  // vértice 1 (centro)
            3.5f, 2.0f, // vértice 2
            3.2f, 0.0f  // vértice 3
        };
        glColor3f(0.0f, 0.15f, 0.65f); // Cor do corpo
        // Desenha o triangulo
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 6; i += 2) {
            glVertex2f(vertices1[i], vertices1[i + 1]);
        }

        //Triangulo inferior
        GLfloat vertices2[] = {
            2.0f, 0.0f,  // vértice 1 (centro)
            3.5f, -2.0f, // vértice 2
            3.2f, 0.0f  // vértice 3
        };
        glColor3f(0.0f, 0.15f, 0.65f); // Cor do corpo
        // Desenha o triangulo
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < 6; i += 2) {
            glVertex2f(vertices2[i], vertices2[i + 1]);
        }

        glEnd();

    //Condição para frame 1
    if (tempo>=5) { //0 ~ 80ms = frame 1

        // Desenhar camada 2 do corpo da barreira
        glPushMatrix();
        glColor3f(0.0f, 0.2f, 0.6f); // Cor do corpo
        glTranslatef(1.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(3.0f, 6.5f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();

        // Desenhar camada 1 corpo da barreira
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
        glTranslatef(0.5f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.5f, 7.0f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();


        //---------------Luz

        // Desenhar luz fundo 1
        glEnable(GL_BLEND); // Habilita o blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
        glPushMatrix();
        glColor4f(1.0f, 1.0f, 1.0f, 0.04f); // Cor com transparência
        glTranslatef(-3.3f, 2.5f, 0.0f); // Posição do corpo
        glScalef(1.4f, 1.4f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 50, 50); // Desenhar o olho
        glPopMatrix();
        glEnd();

        // Desenhar feixe horizontal
        glEnable(GL_BLEND); // Habilita o blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
        glPushMatrix();
        glColor4f(1.0f, 1.0f, 1.0f, 0.05f); // Cor com transparência
        glTranslatef(-3.3f, 2.5f, 0.0f); // Posição da luz
        glScalef(1.6f, 0.4f, 0.2f); // Escala da luz
        glutSolidSphere(0.5, 10, 10); // Desenhar a luz
        glPopMatrix();
        glEnd();


        // Desenhar luz central branca forte
        glEnable(GL_BLEND); // Habilita o blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
        glPushMatrix();
        glColor4f(1.0f, 0.5f, 0.0f, 0.05f); // Cor com transparência
        glTranslatef(-3.3f, 2.5f, 0.0f); // Posição do corpo
        glScalef(0.5f, 0.5f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 50, 50); // Desenhar o olho
        glPopMatrix();
        glEnd();


        // Desenhar o corpo da barreira
        //Borda
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.1f, 7.1f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();
        //Corpo
        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
        glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
        glScalef(2.0f, 7.0f, 1.0f); // Escala do corpo
        glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
        glPopMatrix();

        // Desenhar o olho direito da barreira
        glPushMatrix();
        glColor3f(0.8f, 0.8f, 0.8f); // Cor do olho
        glTranslatef(0.3f, 1.8f, 0.4f); // Posição do olho
        glScalef(0.5f, 1.0f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 10, 10); // Desenhar o olho
        glPopMatrix();

        // Desenhar o olho esquerdo da barreira
        glPushMatrix();
        glColor3f(0.8f, 0.8f, 0.8f); // Cor do olho
        glTranslatef(-0.3f, 1.8f, 0.4f); // Posição do olho
        glScalef(0.5f, 1.0f, 0.2f); // Escala do olho
        glutSolidSphere(0.5, 10, 10); // Desenhar o olho
        glPopMatrix();

        // Desenhar a boca da barreira
        glPushMatrix();
        glClearColor(0.15f, 0.0f, 0.8f, 1.0f);
        glTranslatef(0.0f, -1.0f, 0.4f); // Posição da boca
        glScalef(1.5f, 3.8f, 0.2f); // Escala da boca
        glutSolidSphere(0.5, 50, 50); // Desenhar a boca
        glPopMatrix();

        // Apagar a boca da barreira
        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
        glTranslatef(0.0f, -2.0f, 0.4f); // Posição da boca
        glScalef(1.5f, 2.0f, 0.2f); // Escala da boca
        glutSolidSphere(0.5, 50, 50); // Desenhar a boca
        glPopMatrix();
    }
    //Condição para frame 2
    else{ //80 ~ 160ms frame 2

    // Desenhar camada 2 do corpo da barreira
    glPushMatrix();
    glColor3f(0.0f, 0.2f, 0.6f); // Cor do corpo
    glTranslatef(1.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(3.0f, 6.5f, 1.0f); // Escala do corpo
    glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
    glPopMatrix();

    // Desenhar camada 1 do corpo da barreira
    glPushMatrix();
    glColor3f(0.0f, 0.3f, 0.8f); // Cor do corpo
    glTranslatef(0.5f, 0.0f, 0.0f); // Posição do corpo
    glScalef(2.5f, 7.0f, 1.0f); // Escala do corpo
    glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
    glPopMatrix();

    //---------------Luz
    // Desenhar luz fundo 2
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.05f); // Cor com transparência
    glTranslatef(-3.3f, 2.5f, 0.0f); // Posição do corpo
    glScalef(1.4f, 1.4f, 0.2f); // Escala do olho
    glutSolidSphere(0.5, 50, 50); // Desenhar o olho
    glPopMatrix();
    glEnd();

    // Desenhar feixe vertical
    glEnable(GL_BLEND); // Habilita o blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Configura a função de blending
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.05f); // Cor com transparência
    glTranslatef(-3.3f, 2.5f, 0.0f); // Posição do corpo
    glScalef(0.4f, 1.6f, 0.2f); // Escala do olho
    glutSolidSphere(0.5, 50, 50); // Desenhar o olho
    glPopMatrix();
    glEnd();


    // Desenhar luz central branca forte
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // Cor do olho
    glTranslatef(-3.3f, 2.5f, 0.0f); // Posição do corpo
    glScalef(0.5f, 0.5f, 0.2f); // Escala do olho
    glutSolidSphere(0.5, 50, 50); // Desenhar o olho
    glPopMatrix();

    // Desenhar o corpo da barreira

    //Borda
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(2.15f, 7.1f, 1.0f); // Escala do corpo
    glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
    glPopMatrix();
    //Corpo
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
    glTranslatef(0.0f, 0.0f, 0.0f); // Posição do corpo
    glScalef(2.05f, 7.0f, 1.0f); // Escala do corpo
    glutSolidSphere(0.5, 50, 10); // Desenhar o corpo
    glPopMatrix();

    // Desenhar o olho direito da barreira
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f); // Cor do olho
    glTranslatef(0.3f, 1.8f, 0.4f); // Posição do olho
    glScalef(0.5f, 1.0f, 0.2f); // Escala do olho
    glutSolidSphere(0.5, 10, 10); // Desenhar o olho
    glPopMatrix();

    // Desenhar o olho esquerdo da barreira
    glPushMatrix();
    glColor3f(0.6f, 0.6f, 0.6f); // Cor do olho
    glTranslatef(-0.3f, 1.8f, 0.4f); // Posição do olho
    glScalef(0.5f, 1.0f, 0.2f); // Escala do olho
    glutSolidSphere(0.5, 10, 10); // Desenhar o olho
    glPopMatrix();

    // Desenhar a boca da barreira
    glPushMatrix();
    glClearColor(0.15f, 0.0f, 0.8f, 0.8f);
    glTranslatef(0.0f, -1.0f, 0.4f); // Posição da boca
    glScalef(1.5f, 3.0f, 0.2f); // Escala da boca
    glutSolidSphere(0.5, 50, 50); // Desenhar a boca
    glPopMatrix();

    // Apagar a boca da barreira
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
    glTranslatef(0.0f, -2.0f, 0.4f); // Posição da boca
    glScalef(1.5f, 2.0f, 0.2f); // Escala da boca
    glutSolidSphere(0.5, 50, 50); // Desenhar a boca
    glPopMatrix();
    }

    //Triangulo raivoso dos olhos
    GLfloat vertices3[] = {
        0.0f, 1.5f,  // vértice 1 (centro)
        -0.5f, 2.5f, // vértice 2
        0.5f, 2.5f  // vértice 3
    };
    glColor3f(0.0f, 0.5f, 1.0f); // Cor do corpo
    //Desenha o triangulo
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 6; i += 2) {
        glVertex2f(vertices3[i], vertices3[i + 1]);
    }
    glEnd();
}




//Criação da Pontuação
void drawPontuacao() {

    glColor3f(1.0f, 1.0f, 1.0f); // Define cor branca
    glRasterPos2f(18.0f, 19.0f); // Define posição do texto
    std::string scoreText = "Pontos: " + std::to_string(pontuacao); // Converte pontuação para string
    for (char character : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character); // Renderiza caractere
    }
}



//Checar Colisão com a minhoca
bool checkCollisionMinhoca() {
    // Verificar se as coordenadas dos hitboxes se sobrepõem
    if (peixeX + peixeWidth / 2 >= minhocaX - minhocaWidth / 2 &&
        peixeX - peixeWidth / 2 <= minhocaX + minhocaWidth / 2 &&
        peixeY + peixeHeight / 2 >= minhocaY - minhocaHeight / 2 &&
        peixeY - peixeHeight / 2 <= minhocaY + minhocaHeight / 2) {
        return true; // Colisão detectada
    }
    return false; // Sem colisão
}

//Checar Colisão com a barreira
bool checkCollisionBarreira() {
    // Verificar se as coordenadas dos hitboxes se sobrepõem
    if (peixeX + peixeWidth / 2 >= barreiraX - barreiraWidth / 2 &&
        peixeX - peixeWidth / 2 <= barreiraX + barreiraWidth / 2 &&
        peixeY + peixeHeight / 2 >= barreiraY - barreiraHeight / 2 &&
        peixeY - peixeHeight / 2 <= barreiraY + barreiraHeight / 2) {
        return true; // Colisão detectada
    }
    return false; // Sem colisão
}




//Função para exibir o menu ao pausar
void drawMenu() {

        //Monstro fundo menu
        glColor3f(0.0f, 0.0f, 0.8f); // Cor do mar
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 20.0f);
        glVertex2f(40.0f, 20.0f);
        glVertex2f(40.0f, 0.0f);
        glEnd();

        //Monstro fundo menu
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // Cor preta com 50% de transparência
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 20.0f);
        glVertex2f(40.0f, 20.0f);
        glVertex2f(40.0f, 0.0f);
        glEnd();

        //Corpo gigante
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.4f); // Cor do corpo
        glTranslatef(20.0f, -10.0f, 0.0f);
        glScalef(40.0f, 100.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Corpo gigante
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.5f); // Cor do corpo
        glTranslatef(20.0f, -10.0f, 0.0f);
        glScalef(39.0f, 98.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Corpo gigante 1
        glPushMatrix();
        glColor3f(0.01f, 0.01f, 0.7f);
        glTranslatef(20.0f, -10.0f, 0.0f);
        glScalef(38.0f, 96.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Boca fundo
        glPushMatrix();
        glColor3f(0.0f, 0.1, 0.6f);
        glTranslatef(20.0f, 0.0f, 0.0f);
        glScalef(30.0f, 22.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Corte Boca fundo
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.8f); // Cor do mar
        glTranslatef(20.0f, -3.0f, 0.0f);
        glScalef(30.0f, 10.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Nadadeiras
        glPushMatrix();
        glColor3f(0.01f, 0.45f, 1.0f);
        glTranslatef(20.0f, 13.0f, 0.0f);
        glScalef(16.0f, 8.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Apagar fundo nadadeiras
        glPushMatrix();
        glColor3f(0.01f, 0.01f, 0.7f);
        glTranslatef(20.0f, 17.5f, 0.0f);
        glScalef(31.0f, 12.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Rabo
        glPushMatrix();
        glColor3f(0.06f, 0.25f, 0.85f);
        glTranslatef(20.0f, 17.5f, 0.0f);
        glScalef(8.0f, 4.4f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Apagar Rabo
        glPushMatrix();
        glColor3f(0.01f, 0.01f, 0.7f);
        glTranslatef(20.0f, 18.5f, 0.0f);
        glScalef(16.0f, 4.4f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Monstro Fundo
        //Olho esquerdo
        glPushMatrix();
        glColor3f(0.0f, 0.1, 0.6f);
        glTranslatef(12.0f, 17.0f, 0.0f);
        glScalef(6.0f, 6.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Olho esquerdo 1
        glPushMatrix();
        glColor3f(0.0f, 0.09, 0.58f);
        glTranslatef(12.0f, 17.0f, 0.0f);
        glScalef(5.0f, 5.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Olho direito
        glPushMatrix();
        glColor3f(0.0f, 0.1, 0.6f);
        glTranslatef(28.0f, 17.0f, 0.0f);
        glScalef(6.0f, 6.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Olho direito 1
        glPushMatrix();
        glColor3f(0.0f, 0.09, 0.58f);
        glTranslatef(28.0f, 17.0f, 0.0f);
        glScalef(5.0f, 5.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz
        glPushMatrix();
        glColor3f(0.05f, 0.05f, 0.82f); // Cor do corpo
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(7.0f, 7.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 2
        glPushMatrix();
        glColor3f(0.1f, 0.1f, 0.9f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(5.8f, 5.8f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 3
        glPushMatrix();
        glColor3f(0.15f, 0.15f, 0.95f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(4.5f, 4.5f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 4
        glPushMatrix();
        glColor3f(0.2f, 0.2f, 1.0f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(3.0f, 3.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 5
        glPushMatrix();
        glColor3f(0.25f, 0.25f, 1.0f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(2.0f, 2.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 6
        glPushMatrix();
        glColor3f(0.35f, 0.35f, 1.0f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 7
        glPushMatrix();
        glColor3f(0.4f, 0.4f, 1.0f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 8
        glPushMatrix();
        glColor3f(0.45f, 0.45f, 1.0f);
        glTranslatef(20.0f, 20.0f, 0.0f);
        glScalef(0.25f, 0.25f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 9 elipse
        glPushMatrix();
        glColor3f(0.45f, 0.45f, 1.0f);
        glTranslatef(20.0f, 19.8f, 0.0f);
        glScalef(2.0f, 0.25f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz 10 elipse
        glPushMatrix();
        glColor3f(0.45f, 0.45f, 1.0f);
        glTranslatef(20.0f, 19.8f, 0.0f);
        glScalef(0.25f, 2.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //Luz final
        glPushMatrix();
        glColor3f(0.55f, 0.55f, 1.0f);
        glTranslatef(20.0f, 19.8f, 0.0f);
        glScalef(0.5f, 0.5f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        //Corpo peixe
        glPushMatrix();
        glColor3f(0.1f, 0.3f, 0.85f);
        glTranslatef(20.0f, 13.5f, 0.0f);
        glScalef(8.0f, 4.4f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();
        //corpo 2
        glPushMatrix();
        glColor3f(0.0f, 0.4f, 1.0f);
        glTranslatef(20.0f, 12.0f, 0.0f);
        glScalef(10.4f, 6.4f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();


        //Escurece fundo
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0f, 0.0f, 0.0f, 0.6f); // Cor preta com 50% de transparência
        glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 20.0f);
        glVertex2f(40.0f, 20.0f);
        glVertex2f(40.0f, 0.0f);
        glEnd();

        //Caixa maior
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(20.0f, 10.0f, 0.0f);
        glScalef(12.4f, 9.4f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f);
        glTranslatef(20.0f, 10.0f, 0.0f);
        glScalef(12.0f, 9.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.45f, 1.0f);
        glTranslatef(20.0f, 10.0f, 0.0f);
        glScalef(11.5f, 8.5f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.4f, 1.0f);
        glTranslatef(20.0f, 10.0f, 0.0f);
        glScalef(11.0f, 8.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();


        //Botões:

        //Recomeçar
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(20.0f, 11.5f, 0.0f);
        glScalef(7.2f, 2.2f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f);
        glTranslatef(20.0f, 11.5f, 0.0f);
        glScalef(7.0f, 2.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.05f, 0.55f, 1.0f);
        glTranslatef(20.0f, 11.5f, 0.0f);
        glScalef(6.6f, 1.6f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2f(18.6f, 11.3f); // Define a posição do texto
        std::string recomecarText = "Recomecar"; // Mensagem a ser exibida
        glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
        for (char character : recomecarText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character); // Renderiza cada caractere
        }
        glPopMatrix();

        //Sair
        glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(20.0f, 8.5f, 0.0f);
        glScalef(7.2f, 2.2f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.0f, 0.5f, 1.0f);
        glTranslatef(20.0f, 8.5f, 0.0f);
        glScalef(7.0f, 2.0f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.05f, 0.55f, 1.0f);
        glTranslatef(20.0f, 8.5f, 0.0f);
        glScalef(6.6f, 1.6f, 1.0f);
        glutSolidSphere(0.5, 50, 10);
        glPopMatrix();

                glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2f(19.3f, 8.3f); // Define a posição do texto
        std::string sairText = "Sair"; // Mensagem a ser exibida
        glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
        for (char character : sairText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character); // Renderiza cada caractere
        }
        glPopMatrix();


        if(isGameOver){
            glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
            glPushMatrix();
            glLoadIdentity();
            glRasterPos2f(18.5f, 4.0f); // Define a posição do texto
            std::string gameOverText = "Game Over"; // Mensagem a ser exibida
            glColor3f(1.0f, 1.0f, 1.0f); // Define a cor do texto
            for (char character : gameOverText) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character); // Renderiza cada caractere
            }
        }
}


//Reseta jogo para o estado inicial
void reset() {
    minhocaX = 40.0f;  //Reseta minhoca
    peixeY = 10.0f;  //Reseta peixe
    barreiraX = 60.0f;  //Reseta barreira
    isGameOver = false;  //Remove mensagem de game over
    isPaused = false;  //Despausa o jogo
}

//Encerra a execução do programa
void closeGame(){
    exit(0);
}


//Função de interação com o teclado
void keyboard(unsigned char key, int x, int y) {

    if (key == 'p' || key == 'P') {
        isPaused = !isPaused; // Alterna entre pausar e continuar o jogo
    }

    if (key == 'r' || key == 'R') {
        reset();
    }

    //Controle do peixe
    switch (key) {
        case 'w': // Tecla 'w' para mover para cima
            peixeY += 0.65f;
            glutPostRedisplay(); // Solicita uma nova renderização
            break;
        case 's': // Tecla 's' para mover para baixo
            peixeY -= 0.65f;
            glutPostRedisplay(); // Solicita uma nova renderização
            break;
    }
}

//Função de interação com o mouse
void mouseClick(int button, int state, int x, int y) {
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT); // Obtém a altura da janela

    //Logica dos botões do menu
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && isPaused == true) {

        //Checa se clicou em Restart
        if (x >= 650 && x <= 950 && y >= 300 && y <= 380) {
            reset();
        }
        //Checa se clicou em Sair
        else if (x >= 650 && x <= 950 && y >= 420 && y <= 500) {
            closeGame();
        }
    }

    //Dash do peixe com o mousep
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Verifica se o valor de y está na metade superior ou inferior da tela
        if (y >= windowHeight / 2) {
            // Ação para a metade superior da tela
            peixeY -= 3.0f;
        } else {
            // Ação para a metade inferior da tela
            peixeY += 3.0f;
        }
    }
}


//Função de Dimensionamento de Tela
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 40.0f, 0.0f, 20.0f, -1.0f, 1.0f); // Projeção ortográfica

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//Função de calculos e atualizações de frames
void update(int value) {

    //Se não pausado:
    if (!isPaused) {

        //Contador para gerar as animações dos objetos

        //0 até 80ms = frame 1
        //80 até 160ms = frame 2

        tempo+=1; // Incrementar o tempo a cada 16ms
        if (tempo >= 10) {
            tempo = 0; // Resetar o tempo quando atingir o valor limite
        }

        tempo2+=1; // Incrementar o tempo a cada 16ms
        if (tempo2 >= 100) {
            tempo2 = 0; // Resetar o tempo quando atingir o valor limite
        }

        // Atualizar a posição dos objetos
        minhocaX -= 0.35f; // Velocidade da minhoca
        barreiraX -= 0.30f; // Velocidade da barreira
        bolhasY += 0.10f; //Velocidade Y das volhas
        objeto1X -= 0.10f; //Velocidade X do Objeto Perto
        objeto2X -= 0.05f; //Velocidade X do Objeto Perto
        objeto3X -= 0.025f; //Velocidade X do Objeto Perto


        // Redesenha a cena
        glutPostRedisplay();

        // Redesenha a minhoca
        if (minhocaX < -10.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(2.0f, 18.0f); // Num aleatorios entre 2f e 18f
            minhocaY = dist(gen);  // Gere um novo valor aleatório
            glutPostRedisplay();  // Redesenha a cena

            minhocaX = 40.0f; // Resetar a posição da minhoca para X = 40
        }

        // Redesenha a barreira
            if (barreiraX < -60.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(5.0f, 15.0f); // Num aleatorios entre 2f e 18f
            barreiraY = dist(gen);        // Gere um novo valor aleatório
            glutPostRedisplay();        // Redesenha a cena

            barreiraX = 40.0f; // Resetar a posição da barreira para X = 40
        }


            // Redesenha as bolhas
            if (bolhasY >= 20.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(-2.0f, 21.0f); // Num aleatorios entre 2f e 18f
            bolhasX = dist(gen);        // Gere um novo valor aleatório
            glutPostRedisplay();        // Redesenha a cena

            bolhasY = 0.0f; // Resetar a posição da barreira para X = 40
        }


            //Objetos de fundo
            // Redesenha fundo perto
            if (objeto1X <= -1.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(0.0f, 20.0f); // Num aleatorios entre 0f e 20f
            objeto1Y = dist(gen);        // Gere um novo valor aleatório
            glutPostRedisplay();        // Redesenha a cena

            objeto1X = 40.0f; // Resetar a posição do objeto
        }
            // Redesenha fundo medio
            if (objeto2X <= -3.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(0.0f, 20.0f); // Num aleatorios entre 0f e 20f
            objeto2Y = dist(gen);        // Gere um novo valor aleatório
            glutPostRedisplay();        // Redesenha a cena

            objeto2X = 43.0f; // Resetar a posição do objeto
        }
            // Redesenha fundo longe
            if (objeto3X <= -10.0f) {
            static std::random_device rd;
            static std::mt19937 gen(rd()); // Inicializa o gerador de numeros aleatórios
            static std::uniform_real_distribution<float> dist(0.0f, 20.0f); // Num aleatorios entre 0f e 20f
            objeto3Y = dist(gen);        // Gere um novo valor aleatório
            glutPostRedisplay();        // Redesenha a cena

            objeto3X = 50.0f; // Resetar a posição do objeto
        }



        //Impede peixe de sair da tela
        if (peixeY > 19){
            peixeY = 19;
        }
        if (peixeY < 1){
            peixeY = 1;
        }

        //Checa se colidiu com a barreira
        if (checkCollisionBarreira()) {
            isGameOver = true; // Define o estado de jogo como "Game Over"
            isPaused = true; // Alterna entre pausar e continuar o jogo
        }
    }


    glutPostRedisplay();

    // Configura a próxima atualização após 16ms
    glutTimerFunc(16, update, 0); // 16ms = aproximadamente 60 quadros por segundo

}

//Config e Posicionamento de Objetos na Tela
void display() {

    glClearColor(0.0f, 0.0f, 0.2f, 0.8f); // Define cor de fundo (azul)
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();





    //Objetos de fundo

    // Posicionar e desenhar objeto 3
    glPushMatrix();
    glTranslatef(objeto3X, objeto3Y, 0.0f); // Posição inicial da minhoca
    drawFundoLonge();
    glPopMatrix();
    // Posicionar e desenhar objeto 2
    glPushMatrix();
    glTranslatef(objeto2X, objeto2Y, 0.0f); // Posição inicial da minhoca
    drawFundoMedio();
    glPopMatrix();
    // Posicionar e desenhar objeto 1
    glPushMatrix();
    glTranslatef(objeto1X, objeto1Y, 0.0f); // Posição inicial da minhoca
    drawFundoPerto();
    glPopMatrix();

    // Desenhar ambiente
    glPushMatrix();
    glLoadIdentity();
    drawAmbiente();
    glPopMatrix();


    // Posicionar e desenhar bolhas
    glPushMatrix();
    glTranslatef(bolhasX, bolhasY, 0.0f); // Posição inicial da minhoca
    drawBolhas(); // Desenhar bolha
    glPopMatrix();

    // Posicionar e desenhar a barreira
    glPushMatrix();
    glTranslatef(barreiraX, barreiraY, 0.0f); // Posição inicial da barreira
    drawBarreira(); // Desenhar a barreira
    glPopMatrix();

    // Posicionar e desenhar a minhoca
    glPushMatrix();
    glTranslatef(minhocaX, minhocaY, 0.0f); // Posição inicial da minhoca
    drawMinhoca(); // Desenhar a minhoca
    glPopMatrix();

    // Posicionar e desenhar o peixe
    glPushMatrix();
    glTranslatef(peixeX, peixeY, 0.0f); // Posição inicial do peixe
    drawPeixe(); // Desenhar o peixe
    glPopMatrix();

    // Posicionar e desenhar a pontuação
    glPushMatrix();
    glLoadIdentity();
    drawPontuacao();
    glPopMatrix();


    // Checar Colisão com a minhoca
    if (checkCollisionMinhoca()) {
        minhocaX = -2.0f;
        pontuacao +=1;
    }

    // Checar Colisão com a barreira
    if (checkCollisionBarreira()) {
            minhocaX = -2.0f;
            barreiraX = -4.0f;
            peixeY = 10.0f;
            pontuacao = 0;
    }


    if(isPaused){
    glPushMatrix();
    glLoadIdentity();
    drawMenu();
    glPopMatrix();
    }


    glFlush();
}



//Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1600, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Peixe no OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // Registra a função de callback para o teclado
    glutTimerFunc(0, update, 0); // Configura a primeira chamada para atualização imediata
    glutMouseFunc(mouseClick);
    glutMainLoop();
}