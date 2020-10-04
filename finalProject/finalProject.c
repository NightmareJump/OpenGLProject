/***********************************************************************************************

	File:			finalProject.c

	Description:	Flight Simulator

	Author:			Yanyue Meng

	Stduent ID:		B00797115

**********************************************************************************************/
#include <stdio.h>
#include <freeglut.h>
// the width of window
GLint windowWidth = 1000;
//the height of window
GLint windowHeight = 700;
//the grid size
GLint gridSize = 25;
// switch of wireFrame
GLint wireFrameOn = 1;
// switch of full screen
GLint fullScreenOn = 0;
//switch of right
GLint Right = 0;
//switch of left
GLint left = 0;
// switch of sky and sea frame
GLint skyseaFrame = 0;
//switch of fog
GLint fogOn = 0;
//switch of mountain
GLint mountainOn = 0;
// switch of airdrop
GLint airdropOn = 0;
// switch of snow
GLint snowOn = 0;
// switch of rain
GLint rainOn = 0;
// plane's vertex1
GLfloat vertex1[8000];
// plane's vertex2
GLfloat vertex2[8000];
// plane's vertex3
GLfloat vertex3[8000];
// plane's vertex4
GLfloat vertex4[8000];
// plane's vertex5
GLfloat vertex5[8000];
// plane's vertex6
GLfloat vertex6[8000];
//the normal of plane
GLfloat normal1[8000];
//the normal of plane
GLfloat normal2[8000];
//the normal of plane
GLfloat normal3[8000];
//the normal of plane
GLfloat normal4[8000];
//the normal of plane
GLfloat normal5[8000];
//the normal of plane
GLfloat normal6[8000];
//the normal of plane
GLint face1[2000][50];
//the normal of plane
GLint face2[2000][50];
//the normal of plane
GLint face3[2000][50];
//the normal of plane
GLint face4[2000][50];
//the normal of plane
GLint face5[2000][50];
//the normal of plane
GLint face6[2000][50];
//the normal of plane
GLint face7[2000][50];
//the normal of plane
GLint engineFace1[2000][50];
//the normal of plane
GLint engineFace2[2000][50];
//the lightpink color value
GLfloat lightPink[] = {0.6,0.4,0.9,1};
//yellow color value
GLfloat yellow[] = { 1,1,0,1};
//black color value
GLfloat black[] = { 0,0,0,1 };
//blue color value
GLfloat blue[] = { 0,0,1,1 };
//white color value
GLfloat white[] = { 1,1,1,1 };
//red color value
GLfloat red[] = {1,0,0,1};
//green color value
GLfloat green[] = { 0,1,0,1 };
//limegreen value
GLfloat limegreen[] = {0.2,0.8,0.2};
//darkgreen value
GLfloat darkgreen[] = {0,0.4,0};
// set a theta angle
GLfloat theta = 0.0;
//set the origin of the airdrop
GLfloat fallAir = 20.0;
GLfloat cameraEyeX = 20; //set the eyeX value of camera
GLfloat cameraEyeY = 10.0; // set the eyeY value of camera
GLfloat cameraEyeZ = 20.0; // set the eyeZ value of camera
GLfloat cameraCenterX = 0.0; //set the X value of camera center
GLfloat cameraCenterY = 0.0;//set the Y value of camera center
GLfloat cameraCenterZ = 0.0; // set the Z value of camera center
GLfloat planeMoveX = 0.0;//set the plane move at x 
GLfloat planeMoveY = 0.0;//set the plane move at y
GLfloat planeMoveZ = 0.0;//set the plane move at z
GLfloat moveSpeed = 0.01;// set the movespeed
GLfloat turnLeft = 0.0; // set the angle turn left
GLfloat turnRight = 0.0; //set the angle turn right
GLfloat gamma = 0.0; //set the angle rotate
GLfloat sunlight = -50.0; //set the position of sun
GLint imageWidth, imageHeight; //set image 1 width and height
GLubyte *sea02Data; //set pointer to save sea data
GLuint *sea02; // set a sea ID
GLint image2Width, image2Height; //set image 2 width and height
GLubyte *sky08Data; //set to save sky data
GLuint *sky08; // set a sky Id
GLint image3Width, image3Height; // set image 3 width and height
GLubyte *mount03Data; // set the mount data
GLuint *mount03; //set mountain ID

GLfloat mountVextex[][3] = {
	{0,0,0},{1,0,0},{2,0,0},{3,0,0},{4,0,0},{5,0,0},{6,0,0},{7,0,0},{8,0,0},
	{0,0,1},{1,2,1},{2,2.78,1},{3,2.56,1},{4,2.34,1},{5,2.67,1},{6,2.87,1},{7,2.34,1},{8,0,1},
	{0,0,2},{1,2.3,2},{2,3.45,2},{3,3.77,2},{4,3.88,2},{5,4.43,2},{6,3.87,2},{7,2.11,2},{8,0,2},
	{0,0,3},{1,2.4,3},{2,3.89,3},{3,6.7,3},{4,7.324,3},{5,5.388,3},{6,4.21,3},{7,2.17,3},{8,0,3},
	{0,0,4},{1,2,4},{2,3.45,4},{3,5.8,4},{4,10,4},{5,6.87,4},{6,3.84,4},{7,2.12,4},{8,0,4},
	{0,0,5},{1,2.6,5},{2,4.23,5},{3,6.1,5},{4,5.99,5},{5,7.23,5},{6,3.98,5},{7,2.42,5},{8,0,5},
	{0,0,6},{1,2.9,6},{2,4.10,6},{3,4.0,6},{4,3.42,6},{5,3.87,6},{6,4.45,6},{7,2.68,6},{8,0,5},
	{0,0,7},{1,2.2,7},{2,2.5,7},{3,2.8,7},{4,2.1,7},{5,2.1,7},{6,2.6,7},{7,2.55,7},{8,0,7},
	{0,0,8},{1,0,8},{2,0,8},{3,0,8},{4,0,8},{5,0,8},{6,0,8},{7,0,8},{8,0,8}
};  //set the mount vextex
GLfloat vertices[][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0}, {1.0,1.0,-1.0}, {-1.0,1.0,-1.0},
							{-1.0,-1.0, 1.0}, {1.0,-1.0, 1.0}, {1.0,1.0, 1.0}, {-1.0,1.0, 1.0} };// set the airdrop vertex
GLfloat randColor; //set a random color
GLfloat rainLoop=0.0; //set the move of rain and snow


/*************************************************************************************************

Function:		 basicScene

Description:	 draw the basic scene of simulator

**************************************************************************************************/
void basicScene() {
	// set the ambient to be black
	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	//set the diffuse to be white
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	//set the specular to be white
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	//set the shininess as 100
	glMaterialf(GL_FRONT, GL_SHININESS, 100);
	//set a sphere
	glutSolidSphere(0.3, 80, 80);
	//set the line width to be 5
	glLineWidth(5);
	//set the ambient as black
	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	//set the diffuse to be red
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	//set the soecular to be white
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	//set the shininess to be 100
	glMaterialf(GL_FRONT, GL_SHININESS, 100);
	//draw lines
	glBegin(GL_LINES);
	//set a normal
	glNormal3f(0, 1, 0);
	//set a vertex
	glVertex3f(0, 0, 0);
	//set a normal
	glNormal3f(0, 1, 0);
	//set a vertex
	glVertex3f(3, 0, 0);
	glEnd();
	//set the ambient to be black
	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	//set the diffuse to be green
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);//set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shininess to be 100
	glBegin(GL_LINES); // draw a line
	//glColor4f(0, 1, 0, 1);
	glNormal3f(0, 1, 0); //set a normal
	glVertex3f(0, 0, 0); //set a vertex
	glNormal3f(0, 1, 0); // set a normal
	glVertex3f(0, 3, 0); //set a vertex
	glEnd();
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); // setthe ambient to be black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); // set the diffuse to be blue
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); // set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shiness to be 100
	glBegin(GL_LINES); //draw lines
	glColor4f(0, 0, 1, 1); //set a color
	glNormal3f(0, 1, 0);  //set a normal
	glVertex3f(0, 0, 0); //set a vertex
	glNormal3f(0, 1, 0); // set a normal
	glVertex3f(0, 0, 3); // set a vertex
	glEnd();
	glLineWidth(0.1); // set theline width to be 0.1
	if (wireFrameOn) //judge whether switch on
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //open the line mode
	}
	if (!wireFrameOn) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //open the fill mode
	}
	if (!skyseaFrame) { // judge whether skysea frame on
		glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
		glMaterialfv(GL_FRONT, GL_DIFFUSE, lightPink); // set the diffuse to be pink
		glMaterialfv(GL_FRONT, GL_SPECULAR, white); // set hte specular to be white
		glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shininess to be 100
		for (int i = -gridSize; i <= gridSize; i++) { // set the scale oif grid
			for (int j = -gridSize; j <= gridSize; j++) { // set the scale of grid
				glBegin(GL_QUADS); //draw quads
				glColor3f(0.5, 0.5, 0.5); // set the color
				glNormal3f(0, 1, 0); // set the normal
				glVertex3f(0 + 1 * i, 0, 0 + 1 * j); // set a vertex
				glNormal3f(0, 1, 0); //set a normal
				glVertex3f(1 + 1 * i, 0, 0 + 1 * j); //set a vertex
				glNormal3f(0, 1, 0); // set a normal
				glVertex3f(1 + 1 * i, 0, 1 + 1 * j); //set a vertex
				glNormal3f(0, 1, 0); //set a normal
				glVertex3f(0 + 1 * i, 0, 1 + 1 * j); //set a vertex
				glEnd();
			}
		}
	}
}


/*************************************************************************************************

Function:		 twinEnginePlane

Description:	 read and draw twin engine plane

**************************************************************************************************/
void twinEnginePlane() {
	int a = 0; int b = 0; int c = -1; int d = 0; int e = 0; int f = 0; int i = 0; //set a series variable
	FILE *p; //set a file pointer
	char z[500]; //set a pointer

	p = fopen("cessna.txt","r"); // opent the file
	while ((fgets(z, sizeof(z), p)) != NULL) { //do loop
		char *y = z + 2; 
		if (z[0] == 'v')  { //judge the first the letter
			sscanf_s(z, "v %f %f %f", &vertex1[a], &vertex2[a], &vertex3[a]); //read data
			a++; // next lines
		}
		if (z[0] == 'n') { //judge  the first letter
			sscanf_s(z, "n %f %f %f", &normal1[b], &normal2[b], &normal3[b]);//read data
			b++; //next lines
		}
		if (z[0] == 'g') { // judge the first letter
			c++;
			if (c == 4) { //if another part
				i = 0; //reset the i
			}
			if (c == 6) { // if another part 
				i = 0; //reset the i
			}
			if (c == 7) { // if another part 
				i = 0; //reset the i
			} 
			if (c == 8) { // if another part
				i = 0; //reset the i
			}
			if (c == 14) {  // if another part
				i = 0; //reset the i
			}
			if (c == 26) { //if another part 
					i = 0; //reset the i
				}


		}
		else if (z[0] == 'f' && c <= 3) { //judge first letter and  part
			d = 0;
			while (sscanf_s(y, " %d%n", &e, &f)==1  ) { 
				y += f;
				face1[i][d] = e; //read the face from text
				d++;
			}
			i++;
		}
		else if (z[0] == 'f' && c >= 4 && c <= 5) { //judge first letter and  part
			d = 0;
			while ( sscanf(y, " %d%n", &e, &f)==1 ) {
				y += f;
				face2[i][d] = e;//read the face from text
				d++;
			}
			i++;
		}
		else if (z[0] == 'f' && c == 6) { //judge first letter and  part
			d = 0;
			while (sscanf(y, " %d%n", &e, &f) == 1) {
				y += f;
				face3[i][d] =e;//read the face from text
				d++;
			}
			i++;
		}
		else if (z[0] == 'f' && c == 7) { //judge first letter and  part
			d = 0;
			while (sscanf(y, " %d%n", &e, &f) == 1) {
				y += f;
				face4[i][d] = e;//read the face from text
				d++;
			}
			i++;
		}
		else if (z[0] == 'f' && c >= 8 && c <= 13) {//judge first letter and  part
			d = 0;
			while (sscanf(y, " %d%n", &e, &f) == 1) {
				y += f;
				face5[i][d] = e;//read the face from text
				d++;
			}
			i++;
		}

		else if (z[0] == 'f' && c >= 14 && c <= 25) {//judge first letter and  part
			d = 0;
			while (sscanf(y, " %d%n", &e, &f) ==1 ) {
				y += f;
				face6[i][d] = e;
				d++;
			}
			i++;
		}

		else if (z[0] == 'f' && c >= 26 && c <= 32) {//judge first letter and  part
			d = 0;
			while (sscanf(y, " %d%n", &e, &f) == 1) {
				y += f;
				face7[i][d] = e;
				d++;
			}
			i++;
		}

	}
	fclose(p); //close the file
	
	int l = 0; //set a loop variable
	glPushMatrix(); //push into the matrix
	glTranslatef(5,3,5); //move the plane
	glRotatef(-45,0,1,0); //rotate the plane
	glScalef(3, 3, 3); // make the plane larger
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); // set hte diffuse to be yellow 
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); // set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shininess to be 100
	for (int l = 0; l <= 700; l++) { // make a loop to read
		
		glBegin(GL_POLYGON); // draw  polygons
		for (int j = 0; face1[l][j] > 0; j++) { //make a loop to read normal and vertex

			// read the value of normal in face 
			glNormal3f(normal1[face1[l][j] - 1], normal2[face1[l][j] - 1], normal3[face1[l][j] - 1]);
			//read the value of vertex in face 
			glVertex3f(vertex1[face1[l][j] - 1], vertex2[face1[l][j] - 1], vertex3[face1[l][j] - 1]);

		}
		glEnd();
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); // set teh ambient to be black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black); // set the diffuse to be black
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shininess  to be 100
for (int l = 0; l <=155; l++) { // make a loop to read second part 
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON); //draw the polygon
	for (int j = 0; face2[l][j] > 0; j++) { 

		glNormal3f(normal1[face2[l][j] - 1], normal2[face2[l][j] - 1], normal3[face2[l][j] - 1]); //read the second part normal 
		glVertex3f(vertex1[face2[l][j] - 1], vertex2[face2[l][j] - 1], vertex3[face2[l][j] - 1]); //read the second part vertex
		
	}
	glEnd();
}
glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
glMaterialfv(GL_FRONT, GL_DIFFUSE, red); //set the diffuse to be red
glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular tobe white
glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shininess to be 100

for (int l = 0; l <= 185; l++) { //make a loop to read third part
	glColor3f(1, 0.5, 0.5);
	glBegin(GL_POLYGON); //draw polygon
	for (int j = 0; face3[l][j] > 0; j++) {
		glNormal3f(normal1[face3[l][j] - 1], normal2[face3[l][j] - 1], normal3[face3[l][j] - 1]); // read the third part normal
		glVertex3f(vertex1[face3[l][j] - 1], vertex2[face3[l][j] - 1], vertex3[face3[l][j] - 1]); // read the third part vertex
		}
	glEnd();
}
glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); // set the diffuse to be blue
glMaterialfv(GL_FRONT, GL_SPECULAR, white); // set the specular to be white
glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shininess to be 100

for (int l = 0; l <=174; l++) {		//set the loop to read fourth part 
	glColor3f(0,0,1); 
	glBegin(GL_POLYGON); //draw polygon
	for (int j = 0; face4[l][j] > 0; j++) {
		
		glNormal3f(normal1[face4[l][j] - 1], normal2[face4[l][j] - 1], normal3[face4[l][j] - 1]); // read the fifth part normal
		glVertex3f(vertex1[face4[l][j] - 1], vertex2[face4[l][j] - 1], vertex3[face4[l][j] - 1]); // read the fourth part vertex
		}
	glEnd();
}
glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); //set the diffuse to be blue
glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular tobe white
glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shininess to be 100
for (int l = 0; l <= 761; l++) { // read the fifth part
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	for (int j = 0; face5[l][j] > 0; j++) {

		glNormal3f(normal1[face5[l][j] - 1], normal2[face5[l][j] - 1], normal3[face5[l][j] - 1]); //read the fifth part normal
		glVertex3f(vertex1[face5[l][j] - 1], vertex2[face5[l][j] - 1], vertex3[ face5[l][j] - 1]); // read the fifth part vertex
		}
	glEnd();
}
glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); //set the diffuse to be blue
glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular to be white
glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shininess to be 100

for (int l = 0; l <= 1616; l++) { //read the sixth part
	glColor3f(0,0,1);
	glBegin(GL_POLYGON); //draw polygon
	for (int j = 0; face6[l][j] > 0; j++) {

		glNormal3f(normal1[face6[l][j] - 1], normal2[face6[l][j] - 1], normal3[face6[l][j] - 1]); //read sixth part naormal
		glVertex3f(vertex1[face6[l][j] - 1], vertex2[face6[l][j] - 1], vertex3[face6[l][j] - 1]); //read sixth part vertex
		}
	glEnd();
}
glMaterialfv(GL_FRONT, GL_AMBIENT, black); // set the ambient to be black
glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); //set the diffuse to be yellow 
glMaterialfv(GL_FRONT, GL_SPECULAR, white); // setthe specular to be white
glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shiness tobe 100

for (int l = 0; l <= 742; l++) { //read the seventh part
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON); //draw polygon
	for (int j = 0; face7[l][j] > 0; j++) {

		glNormal3f(normal1[face7[l][j] - 1], normal2[face7[l][j] - 1], normal3[face7[l][j] - 1]); //read the seventh part normal
		glVertex3f(vertex1[face7[l][j] - 1], vertex2[face7[l][j] - 1], vertex3[face7[l][j] - 1]); //read the seventh part vertex
	
	}
	glEnd();
	}
	
	glPopMatrix(); //pop the maxtrix
}

/*************************************************************************************************

Function:		 propeller

Description:	 draw the propeller for the plane

**************************************************************************************************/

void propeller() {
	int a = 0; int b = 0; int c = -1; int d = 0; int e = 0; int f = 0; int i = 0; //set a series of variable
	FILE *pt; //set a file pointer
	char z[500]; //set the array

	pt = fopen("propeller.txt", "r"); //opem the txt
	while ((fgets(z, sizeof(z), pt)) != NULL) {
		char *y = z + 2;
		if (z[0] == 'v') { //judge the first letter
			sscanf_s(z, "v %f %f %f", &vertex4[a], &vertex5[a], &vertex6[a]); //read tehe line
			a++; //next line
		}
		if (z[0] == 'n') {  //judge the first letter
			sscanf_s(z, "n %f %f %f", &normal4[b], &normal5[b], &normal6[b]);//read tehe line
			b++;
		}
		if (z[0] == 'g') { //judge the first letter
			c++;
			if (c == 1) { //judge whether second part
				i = 0;
			}
			
		}

		else if (z[0] == 'f' && c == 0) { //judge the first letter
			d = 0;
			while (sscanf_s(y, " %d%n", &e, &f)==1  ) {
				y += f;
				engineFace1[i][d] = e; // write the first part face
				d++; //next line
			}
			i++;
		}
	else if (z[0] == 'f' && c == 1) { //judge the second letter
			d = 0;
			while (sscanf_s(y, " %d%n", &e, &f)== 1 ) {
				y += f;
				engineFace2[i][d] = e; //write the second part face
				d++; //next liene
			}
			i++;
		}
		
	}
	fclose(pt); //close the file

	glPushMatrix(); //push the propellor into maxtrix
	glTranslatef(5, 3, 5); //move the stuff
	glRotatef(-45, 0, 1, 0); //rotate it
	glScalef(3, 3, 3); //make it larger
	glTranslatef(-3, -0.15, 0.35); // move it
	glRotatef(-theta, 1, 0, 0); //rotate it
	glTranslatef(3, 0.15, -0.35); // move it rotate it
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); // set the ambient as black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); //set the diffuse to be yellow
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shiiness to be 100
	for (int l = 0; l <= 200; l++) { //make a loop to read first part
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON); //draw polygon
		for (int j = 0; engineFace1[l][j] > 0; j++) {

			glNormal3f(normal4[engineFace1[l][j] - 1], normal5[engineFace1[l][j] - 1], normal6[engineFace1[l][j] - 1]); //read normal
			glVertex3f(vertex4[engineFace1[l][j] - 1], vertex5[engineFace1[l][j] - 1], vertex6[engineFace1[l][j] - 1]); //read vertex

		}
		glEnd();
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to be black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); //set the diffuse to be blue
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); // set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); // set the shiiness to be 100
	for (int l = 0; l <= 12; l++) { //read the second part of plane
		glColor3f(0, 0, 1); 
		glBegin(GL_POLYGON);	//draw the polygon
		for (int j = 0; engineFace2[l][j] > 0; j++) {

			glNormal3f(normal4[engineFace2[l][j] - 1], normal5[engineFace2[l][j] - 1], normal6[engineFace2[l][j] - 1]); //rad the normal
			glVertex3f(vertex4[engineFace2[l][j] - 1], vertex5[engineFace2[l][j] - 1], vertex6[engineFace2[l][j] - 1]); //read vertex

		}
		glEnd();
	}
	glPopMatrix(); //pop the matrix
	
	glPushMatrix(); // push the second one
	glTranslatef(6.7, 3.1, 3.8);  //move it
	glRotatef(-45, 0, 1, 0); //rotate it
	glScalef(3, 3, 3); //make it larger
	glTranslatef(-3, -0.15, 0.35); // move it
	glRotatef(theta, 1, 0, 0); //rotate it
	glTranslatef(3, 0.15, -0.35); //move it
	glMaterialfv(GL_FRONT, GL_AMBIENT, black);//set the ambient as black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow); //set the diffuse to be  yellow
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shiiness to b 100
	
	//read the first part
	for (int l = 0; l <= 200; l++) { 
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		for (int j = 0; engineFace1[l][j] > 0; j++) {

			glNormal3f(normal4[engineFace1[l][j] - 1], normal5[engineFace1[l][j] - 1], normal6[engineFace1[l][j] - 1]);
			glVertex3f(vertex4[engineFace1[l][j] - 1], vertex5[engineFace1[l][j] - 1], vertex6[engineFace1[l][j] - 1]);

		}
		glEnd();
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, black); //set the ambient to b black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue); //set tehe diffuse to be blue
	glMaterialfv(GL_FRONT, GL_SPECULAR, white); //set the specular to be white
	glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shininess to be 100

	//read the second part
	for (int l = 0; l <= 12; l++) { 
		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
		for (int j = 0; engineFace2[l][j] > 0; j++) {

			glNormal3f(normal4[engineFace2[l][j] - 1], normal5[engineFace2[l][j] - 1], normal6[engineFace2[l][j] - 1]);
			glVertex3f(vertex4[engineFace2[l][j] - 1], vertex5[engineFace2[l][j] - 1], vertex6[engineFace2[l][j] - 1]);

		}
		glEnd();
	}
	glPopMatrix(); //pop the matrix 
}

/*************************************************************************************************

Function:		 skyseaTexture

Description:	 mapping the sky and sea

**************************************************************************************************/

void skyseaTexture()
{
	// the ID of the image file
	FILE *sea;
	// maxValue
	int  maxValue=0;
	// total number of pixels in the image
	int  totalPixels;
	// temporary character
	char tempChar;
	// counter variable for the current pixel in the image
	int i;
	// array for reading in header information
	char headerLine[100];
	// if the original values are larger than 255
	float RGBScaling;
	// temporary variables for reading in the red, green and blue data of each pixel
	int red, green, blue;
	// open the image file for reading
	sea = fopen("sea02.ppm", "r");
	// read in the first header line
	fscanf(sea, "%[^\n] ", headerLine);
	fscanf(sea, "%d %d %d", &imageWidth, &imageHeight, &maxValue);
	// compute the total number of pixels in the image
	totalPixels = imageWidth * imageHeight;
	// allocate enough memory for the image  (3*) because of the RGB data
	sea02Data = malloc(3 * sizeof(GLuint) * totalPixels);
	//sclaing to suitable size
	RGBScaling = 255.0 / maxValue;
	if (maxValue == 255)
	{
		for (i = 0; i < totalPixels; i++)
		{
			// read in the current pixel from the file
			fscanf(sea, "%d %d %d", &red, &green, &blue);

			// store the red, green and blue data of the current pixel in the data array
			sea02Data[3 * totalPixels - 3 * i - 3] = red;
			sea02Data[3 * totalPixels - 3 * i - 2] = green;
			sea02Data[3 * totalPixels - 3 * i - 1] = blue;
		}
	}
	else  // need to scale up the data values
	{
		for (i = 0; i < totalPixels; i++)
		{
			// read in the current pixel from the file
			fscanf(sea, "%d %d %d", &red, &green, &blue);

			// store the red, green and blue data of the current pixel in the data array
			sea02Data[3 * totalPixels - 3 * i - 3] = red * RGBScaling;
			sea02Data[3 * totalPixels - 3 * i - 2] = green * RGBScaling;
			sea02Data[3 * totalPixels - 3 * i - 1] = blue * RGBScaling;
		}
	}
	// close the image file
	fclose(sea);


	// the ID of the image file
	FILE *sky;
	// maxValue
	int  maxValue2 = 0;
	// total number of pixels in the image
	int  totalPixels2;
	// temporary character
	char tempChar2;
	// counter variable for the current pixel in the image
	int i2;
	// array for reading in header information
	char headerLine2[100];
	// if the original values are larger than 255
	float RGBScaling2;
	// temporary variables for reading in the red, green and blue data of each pixel
	int red2, green2, blue2;
	// open the image file for reading
	sky = fopen("sky08.ppm", "r");
	// read in the first header line
	//    - "%[^\n]"  matches a string of all characters not equal to the new line character ('\n')
	//    - so we are just reading everything up to the first line break
	fscanf(sea, "%[^\n] ", headerLine2);
	fscanf(sea, "%d %d %d", &image2Width, &image2Height, &maxValue2);
	// compute the total number of pixels in the image
	totalPixels2 = image2Width * image2Height;
	// allocate enough memory for the image  (3*) because of the RGB data
	sky08Data = malloc(3 * sizeof(GLuint) * totalPixels2);
	RGBScaling2 = 255.0 / maxValue2;
	if (maxValue2 == 255)
	{
		for (i2 = 0; i2 < totalPixels2; i2++)
		{
			// read in the current pixel from the file
			fscanf(sea, "%d %d %d", &red2, &green2, &blue2);

			// store the red, green and blue data of the current pixel in the data array
			sky08Data[3 * totalPixels2 - 3 * i2 - 3] = red2;
			sky08Data[3 * totalPixels2 - 3 * i2 - 2] = green2;
			sky08Data[3 * totalPixels2 - 3 * i2 - 1] = blue2;
		}
	}
	else  // need to scale up the data values
	{
		for (i2 = 0; i2 < totalPixels2; i2++)
		{
			// read in the current pixel from the file
			fscanf(sky, "%d %d %d", &red2, &green2, &blue2);

			// store the red, green and blue data of the current pixel in the data array
			sky08Data[3 * totalPixels2 - 3 * i2 - 3] = red2 * RGBScaling2;
			sky08Data[3 * totalPixels2 - 3 * i2 - 2] = green2 * RGBScaling2;
			sky08Data[3 * totalPixels2 - 3 * i - 1] = blue2 * RGBScaling2;
		}
	}
	// close the image file
	fclose(sky);


	glGenTextures(1, &sea02);
	glBindTexture(GL_TEXTURE_2D, sea02);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// tell openGL how to scale the texture image down if needed
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set the current texture
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, imageWidth, imageHeight,
		GL_RGB, GL_UNSIGNED_BYTE, sea02Data);

	glGenTextures(1, &sky08);
	glBindTexture(GL_TEXTURE_2D, sky08);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// tell openGL how to scale the texture image down if needed
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set the current texture
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3,image2Width, image2Height,
		GL_RGB, GL_UNSIGNED_BYTE, sky08Data);

}

/*************************************************************************************************

Function:		 fog 

Description:	 toggle the fog

**************************************************************************************************/

void fog()
{

	glEnable(GL_FOG);
	// set the color of the fog
	GLfloat tranparentPink[] = {1,0.5,0.5,0.3};
	glFogfv(GL_FOG_COLOR, tranparentPink);
	glFogf(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.03);
}

/*************************************************************************************************

Function:		 skySeaFrame

Description:	 draw frame of sky and frame

**************************************************************************************************/

void skySeaFrame() {
	if (skyseaFrame) // judge whether switch on
	{	
		
		glPushMatrix(); //push in to matrix
		glTranslatef(0, 56, 0); //move it 
		glRotatef(90, 1, 0, 0); //rotate it
		GLUquadricObj* skyframe; //create a point
		skyframe = gluNewQuadric(); //value
		gluQuadricDrawStyle(skyframe, GLU_FILL); //set draw style
		glShadeModel(GL_SMOOTH); //set model
		gluQuadricNormals(skyframe, GLU_SMOOTH); //set normal
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white); //set ambient
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white); //set diffuse
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white); //set specular
		glMaterialfv(GL_FRONT, GL_EMISSION, white); //set emission
		glMaterialf(GL_FRONT, GL_SHININESS, 50); //set shininess
		glEnable(GL_TEXTURE_2D); //open texture 2d
		gluQuadricTexture(skyframe, GL_TRUE); //open texture
		glBindTexture(GL_TEXTURE_2D, sky08); //maping
		gluQuadricTexture(skyframe, sky08); //mapping to skyframe
		gluCylinder(skyframe, 110, 60, 60, 20, 20); //draw a cylinder
		gluDeleteQuadric(skyframe); //delete the node
		glDisable(GL_TEXTURE_2D); // close 2d texture
		glMaterialfv(GL_FRONT, GL_EMISSION, black); //set emission
		glPopMatrix(); //pop the matrix

		//the similar way mapping  sea
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glRotatef(90, 1, 0, 0);
		GLUquadricObj* seaframe;
		seaframe = gluNewQuadric();
		gluQuadricDrawStyle(seaframe, GLU_FILL);
		glShadeModel(GL_SMOOTH);
		gluQuadricOrientation(seaframe, GLU_OUTSIDE);
		gluQuadricNormals(seaframe, GLU_SMOOTH);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
		glMaterialfv(GL_FRONT, GL_EMISSION, white);
		glMaterialf(GL_FRONT, GL_SHININESS, 50);		
		glEnable(GL_TEXTURE_2D);
		gluQuadricTexture(seaframe, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, sea02);
		gluQuadricTexture(seaframe, sea02);
		gluDisk(seaframe, 0, 120, 30, 30);
		gluDeleteQuadric(seaframe);
		glMaterialfv(GL_FRONT, GL_EMISSION, black);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
}

/*************************************************************************************************

Function:		 mountain

Description:	draw teh mountain

**************************************************************************************************/

void mountain() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black); //set the ambient 
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, darkgreen); //set the diffuse
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white); //set the specular
	glMaterialf(GL_FRONT, GL_SHININESS, 50); //set the shiiness

	//read the mountain
int i;
for (i = 0; i <= 7; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[i]);
	glVertex3fv(mountVextex[i + 1]);
	glVertex3fv(mountVextex[i + 10]);
	glVertex3fv(mountVextex[i + 9]);
	glEnd();
}
for (i = 1; i <= 7; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i]);
	glVertex3fv(mountVextex[9 * i + 1]);
	glVertex3fv(mountVextex[9 * i + 10]);
	glVertex3fv(mountVextex[9 * i + 9]);
	glEnd();
}
for (i = 0; i <= 7; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[63 + i]);
	glVertex3fv(mountVextex[63 + i + 1]);
	glVertex3fv(mountVextex[63 + i + 10]);
	glVertex3fv(mountVextex[63 + i + 9]);
	glEnd();
}
for (i = 1; i <= 7; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i + 7]);
	glVertex3fv(mountVextex[9 * i + 1 + 7]);
	glVertex3fv(mountVextex[9 * i + 10 + 7]);
	glVertex3fv(mountVextex[9 * i + 9 + 7]);
	glEnd();
}

glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black); //set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, green); //set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white); //set the specular
glMaterialf(GL_FRONT, GL_SHININESS, 50); //set the shininess
for (i = 10; i <= 15; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[i]);
	glVertex3fv(mountVextex[i + 1]);
	glVertex3fv(mountVextex[i + 10]);
	glVertex3fv(mountVextex[i + 9]);
	glEnd();
}
for (i = 1; i <= 6; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i+1]);
	glVertex3fv(mountVextex[9 * i + 1+1]);
	glVertex3fv(mountVextex[9 * i + 10+1]);
	glVertex3fv(mountVextex[9 * i + 9+1]);
	glEnd();
}
for (i = 0; i <= 5; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[55 + i]);
	glVertex3fv(mountVextex[55 + i + 1]);
	glVertex3fv(mountVextex[55 + i + 10]);
	glVertex3fv(mountVextex[55 + i + 9]);
	glEnd();
}
for (i = 1; i <= 6; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i + 6]);
	glVertex3fv(mountVextex[9 * i + 1 +6 ]);
	glVertex3fv(mountVextex[9 * i + 10 + 6]);
	glVertex3fv(mountVextex[9 * i + 9 + 6]);
	glEnd();
}

glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);//set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, limegreen);//set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);//set the specular
glMaterialf(GL_FRONT, GL_SHININESS, 50); //set the shininess
for (i = 20; i <= 23; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[i]);
	glVertex3fv(mountVextex[i + 1]);
	glVertex3fv(mountVextex[i + 10]);
	glVertex3fv(mountVextex[i + 9]);
	glEnd();
}
for (i = 2; i <= 5; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i + 2]);
	glVertex3fv(mountVextex[9 * i + 1 + 2]);
	glVertex3fv(mountVextex[9 * i + 10 + 2]);
	glVertex3fv(mountVextex[9 * i + 9 + 2]);
	glEnd();
}
for (i = 0; i <= 3; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[47 + i]);
	glVertex3fv(mountVextex[47 + i + 1]);
	glVertex3fv(mountVextex[47 + i + 10]);
	glVertex3fv(mountVextex[47 + i + 9]);
	glEnd();
}
for (i = 2; i <= 5; i++) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[9 * i + 5]);
	glVertex3fv(mountVextex[9 * i + 1 + 5]);
	glVertex3fv(mountVextex[9 * i + 10 + 5]);
	glVertex3fv(mountVextex[9 * i + 9 + 5]);
	glEnd();
}

glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);//set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);//set the ambient 
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);//set the specular
glMaterialf(GL_FRONT, GL_SHININESS, 50); //set the shininess

//draw the montain top
	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[30]);
	glVertex3fv(mountVextex[30 + 1]);
	glVertex3fv(mountVextex[30 + 10]);
	glVertex3fv(mountVextex[30 + 9]);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[31]);
	glVertex3fv(mountVextex[32]);
	glVertex3fv(mountVextex[40]);
	glVertex3fv(mountVextex[41]);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[39]);
	glVertex3fv(mountVextex[40]);
	glVertex3fv(mountVextex[48]);
	glVertex3fv(mountVextex[49]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0.4, 0);
	glVertex3fv(mountVextex[40]);
	glVertex3fv(mountVextex[41]);
	glVertex3fv(mountVextex[49]);
	glVertex3fv(mountVextex[50]);
	glEnd();

}

/*************************************************************************************************

Function:		 montainmapping 

Description:	mapping mountain

**************************************************************************************************/

void mountainMapping() {
	// the ID of the image file
	FILE *mountain;
	// maxValue
	int  maxValue3 = 0;
	// total number of pixels in the image
	int  totalPixels3;
	// temporary character
	char tempChar3;
	// counter variable for the current pixel in the image
	int i3;
	// array for reading in header information
	char headerLine3[100];
	// if the original values are larger than 255
	float RGBScaling3;
	// temporary variables for reading in the red, green and blue data of each pixel
	int red3, green3, blue3;
	// open the image file for reading
	mountain = fopen("mount03.ppm", "r");
	// read in the first header line
	//    - "%[^\n]"  matches a string of all characters not equal to the new line character ('\n')
	//    - so we are just reading everything up to the first line break
	fscanf(mountain, "%[^\n] ", headerLine3);
	fscanf(mountain, "%d %d %d", &image3Width, &image3Height, &maxValue3);
	// compute the total number of pixels in the image
	totalPixels3 = image3Width * image3Height;
	// allocate enough memory for the image  (3*) because of the RGB data
	mount03Data = malloc(3 * sizeof(GLuint) * totalPixels3);
	RGBScaling3 = 255.0 / maxValue3;
	if (maxValue3 == 255)
	{
		for (i3 = 0; i3 < totalPixels3; i3++)
		{
			// read in the current pixel from the file
			fscanf(mountain, "%d %d %d", &red3, &green3, &blue3);

			// store the red, green and blue data of the current pixel in the data array
			mount03Data[3 * totalPixels3 - 3 * i3 - 3] = red3;
			mount03Data[3 * totalPixels3- 3 * i3 - 2] = green3;
			mount03Data[3 * totalPixels3 - 3 * i3 - 1] = blue3;
		}
	}
	else  // need to scale up the data values
	{
		for (i3 = 0; i3 < totalPixels3; i3++)
		{
			// read in the current pixel from the file
			fscanf(mountain, "%d %d %d", &red3, &green3, &blue3);

			// store the red, green and blue data of the current pixel in the data array
			mount03Data[3 * totalPixels3 - 3 * i3 - 3] = red3 * RGBScaling3;
			mount03Data[3 * totalPixels3 - 3 * i3 - 2] = green3 * RGBScaling3;
			mount03Data[3 * totalPixels3 - 3 * i3 - 1] = blue3 * RGBScaling3;
		}
	}
	// close the image file
	fclose(mountain);

	glGenTextures(1, &mount03);
	glBindTexture(GL_TEXTURE_2D, mount03);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// tell openGL how to scale the texture image down if needed
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set the current texture
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image3Width, image3Height,
		GL_RGB, GL_UNSIGNED_BYTE, mount03Data);
}

/*************************************************************************************************

Function:		 parachute

Description:	draw a parachute

**************************************************************************************************/

void parachute() {
	glLineWidth(3);//set the line width
	//draw the lines of parachute
	glBegin(GL_LINES);
	glColor3fv(black);
	glVertex3f(0, 2, 0);
	glVertex3f(2, 5, 2);
	glEnd();

	//draw the lines of parachute
	glBegin(GL_LINES);
	glColor3fv(black);
	glVertex3f(0, 2, 0);
	glVertex3f(2, 5, -2);
	glEnd();

	//draw the lines of parachute
	glBegin(GL_LINES);
	glColor3fv(black);
	glVertex3f(0, 2, 0);
	glVertex3f(-2, 5, 2);
	glEnd();

	//draw the lines of parachute
	glBegin(GL_LINES);
	glColor3fv(black);
	glVertex3f(0, 2, 0);
	glVertex3f(-2, 5, -2);
	glEnd();

	//draw the top of parachute and map it
	glPushMatrix(); 
	glTranslatef(0, 5, 0);
	glRotatef(-90, 1, 0, 0);
	GLUquadricObj* parachute;
	parachute = gluNewQuadric();
	gluQuadricDrawStyle(parachute, GLU_FILL);
	glShadeModel(GL_SMOOTH);
	gluQuadricNormals(parachute, GLU_SMOOTH);
	gluQuadricOrientation(parachute, GLU_OUTSIDE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, darkgreen);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);
	glEnable(GL_TEXTURE_2D);
	gluQuadricTexture(parachute, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, mount03);
	gluQuadricTexture(parachute, mount03);
	gluCylinder(parachute, 2.9, 0, 1.5, 20, 20);
	gluDeleteQuadric(parachute);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

/*************************************************************************************************

Function:		 airdrop

Description:	 draw the airdrop

**************************************************************************************************/

void airdrop() {
	glDisable(GL_LIGHTING); // disable the ligtning

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir > 0) //not reach the sea
	{
		glColor3f(0, randColor, 0); //set a random color
	}
	else
	{
		glColor3fv(green);  //set a greencolor
	}
	glVertex3f(1,2,1);
	glVertex3f(1, 2, -1);
	glVertex3f(-1, 2, -1);
	glVertex3f(-1, 2, 1);
	glEnd();

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir > 0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	glVertex3f(-1, 0, -1);
	glVertex3f(-1, 0, 1);
	glEnd();

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir >0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(1, 0, 1);
	if (fallAir > 0)//not reach the sea
	{
		glColor3f(0, randColor, 0);//set a random color
	}
	else
	{
		glColor3fv(green);
	}
	glVertex3f(1, 2, 1);
	glVertex3f(-1, 2, 1);
	if (fallAir > 0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(-1, 0, 1);
	glEnd();

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir > 0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	if (fallAir > 0)//not reach the sea
	{
		glColor3f(0, randColor, 0);//set a random color
	}
	else
	{
		glColor3fv(green);
	}
	glVertex3f(1,2 , -1);
	glVertex3f(1, 2 , 1);
	glEnd();

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir > 0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(1, 0, -1);
	glVertex3f(-1, 0, -1);
	if (fallAir >0)//not reach the sea
	{
		glColor3f(0, randColor, 0);//set a random color
	}
	else
	{
		glColor3fv(green);
	}
	glVertex3f(-1, 2, -1);
	glVertex3f(1, 2, -1);
	glEnd();

	//draw the airdrop
	glBegin(GL_POLYGON);
	if (fallAir > 0) {//not reach the sea
		glColor3f(randColor, 0, 0);//set a random color
	}
	else {
		glColor3fv(red);
	}
	glVertex3f(-1, 0, -1);
	glVertex3f(-1, 0, 1);
	if (fallAir > 0)//not reach the sea
	{
		glColor3f(0, randColor, 0);//set a random color
	}
	else
	{
		glColor3fv(green);
	}
	glVertex3f(-1, 2, 1);
	glVertex3f(-1, 2, -1);
	glEnd();

	glEnable(GL_LIGHTING); //enable the ligting

}

/*************************************************************************************************

Function:		 rain

Description:	make it rain

**************************************************************************************************/

void rain() {
	
	int i, j, k;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue); // set the ambiient
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue); //set the diffuse
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white); //set the specul;ar
	glMaterialf(GL_FRONT, GL_SHININESS, 100); //set the shininess
	glLineWidth(2); //set the line width ot be 2

	//do loop tp draw the rain
	for (i = -30; i <= 30; i+=2) {
		for (j = 0; j <= 30; j+=2) {
			for (k =-30; k <= 30; k+=3) {
	glBegin(GL_LINES);
	glVertex3f(i,j,k);
	glVertex3f(i, j+0.1, k);
	glEnd();
			}
		}
	}
	


}

/*************************************************************************************************

Function:		 snow

Description:	 make it snow

**************************************************************************************************/

void snow() {
	glDisable(GL_LIGHTING); //disable the lighting

	glPointSize(3.0); //set the point size
	int i, j, k;
	glColor3f(1, 1, 1);
	for (i = -30; i <= 30; i=i+2) {
		for (j = 0; j <= 30; j+=2) {
			for (k = -30; k <= 30; k+=3) {
				glBegin(GL_POINTS);
				glVertex3f(i, j, k);
				glEnd();
			}
		}
	}
	glEnable(GL_LIGHTING); //enable the lighting

}

/*************************************************************************************************

Function:		 myDisplay

Description:	display the different needed thing in this function

**************************************************************************************************/
void myDisplay() {
	//clear the color buffer and depthe buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	GLfloat sunPosition[] = { sunlight, 30, 0, 1 }; //set thesun position
	glLoadIdentity();	// load the identity matrix into the model view matrix
	
	glLightfv(GL_LIGHT0, GL_POSITION, sunPosition); //set light
	gluLookAt(cameraEyeX, cameraEyeY, cameraEyeZ, 
		cameraCenterX, cameraCenterY, cameraCenterZ, 0, 1, 0); //set the camera

	basicScene(); //use basicscene function
	glPushMatrix(); //push into matrix
	glTranslatef(15 + planeMoveX, 7 + planeMoveY, 15 + planeMoveZ); //move it 
	if (Right) //make tile
	{
		glRotatef(-gamma,1,0,1);
	}
	if (left) //make tile
	{
		glRotatef(-gamma, 1, 0, 1);
	}
	glTranslatef(-5,-3,-5); //move it
	twinEnginePlane();	 //draw plane
	propeller(); //draw propeller 
	glPopMatrix(); //pop matrix
	skySeaFrame(); //draw skysea frame

	//set fullscreen
	if (fullScreenOn) { 
		glutFullScreen();
	}
	if (!fullScreenOn)
	{
		glutPositionWindow(0, 0);
		glutReshapeWindow(1000, 700);
	}

	//set skysea frame and fog
	if (skyseaFrame && fogOn) {
		fog();
	}
	else {
		glDisable(GL_FOG);
	}

	//set the mountain
	if (mountainOn)
	{
		glPushMatrix();
		glTranslatef(-15, 0, -20);
		glScalef(2,1,1.5);
		mountain();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-50, 0, -30);
		glScalef(2.5, 2, 4);
		mountain();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10, 0, -50);
		glScalef(5, 1, 3);
		mountain();
		glPopMatrix();
	}

	//draw the airdrop
	if (airdropOn)
	{
		glPushMatrix();
		glTranslatef(-5,fallAir,5);
		airdrop();
		if (fallAir > 0)
		{
			parachute();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0, fallAir, -0);
		airdrop();
		if (fallAir > 0)
		{
			parachute();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(5, fallAir, -10);
		airdrop();
		if (fallAir > 0)
		{
			parachute();
		}
		glPopMatrix();
	}

	//draw the rain and snow
	glPushMatrix();
	glRotatef(30,1,0,1);
	glTranslatef(0, rainLoop, 0);
	if (rainOn)
	{
		rain();
	}
	if (snowOn)
	{
		snow();
	}
	glPopMatrix();
	// swap the drawing buffers
	glutSwapBuffers();
}

/************************************************************************

Function:		 myKeyboard

Description:	to turn on and turn off different function

*************************************************************************/
void myKeyboard(unsigned char key, int x, int y)
{
	//turn on the wireFrame
	if ((key == 'w' || key == 'W') && wireFrameOn == 0) {
		wireFrameOn = 1;
	}
	//turn off the wireframe
	else if ((key == 'w' || key == 'W') && wireFrameOn == 1) {
		wireFrameOn = 0;
	}
	//turn on the fullsceen
	if ((key == 'f' || key == 'F') && fullScreenOn == 0) {
		fullScreenOn = 1;
	}
	//turn off the fullscreen
	else if ((key == 'f' || key == 'F') && fullScreenOn == 1) {
		fullScreenOn = 0;
	}
	//turn on the skyseaframe
	if ((key == 's' || key == 'S') && skyseaFrame == 0) {
		skyseaFrame = 1;
	}
	//turn off the skyseaframe
	else if ((key == 's' || key == 'S') && skyseaFrame == 1) {
		skyseaFrame = 0;
	}
	//turn on the fog
	if ((key == 'b' || key == 'B') && fogOn == 0) {
		fogOn = 1;
	}
	//turn off the gog
	else if ((key == 'b' || key == 'B') && fogOn == 1) {
		fogOn = 0;
	}
	//turn on the mountain
	if ((key == 'm' || key == 'M') && mountainOn == 0) {
		mountainOn = 1;
	}
	//turn off the mountain
	else if ((key == 'm' || key == 'M') && mountainOn == 1) {
		mountainOn = 0;
	}
	//turn on the airdrop
	if ((key == 'a' || key == 'A') && airdropOn == 0) {
		airdropOn = 1;
	}
	//turn off the airdrop
	else if ((key == 'a' || key == 'A') && airdropOn == 1) {
		airdropOn = 0;
	}
	//turn on the rain
	if ((key == 'r' || key == 'R') && rainOn == 0) {
		rainOn = 1;
	}
	//turn off the rain
	else if ((key == 'r' || key == 'R') && rainOn == 1) {
		rainOn = 0;
	}
	//turn on the snow
	if ((key == 'e' || key == 'E') && snowOn == 0) {
		snowOn = 1;
	}
	//turn off the snow
	else if ((key == 'e' || key == 'E') && snowOn == 1) {
		snowOn = 0;
	}
	// redraw the new state
	glutPostRedisplay();
}

/************************************************************************

Function:		 specialKeyboard

Description:	 make the plane move through press the key

*************************************************************************/
void specialKeyboard(int key, int x, int y)
{
	// make the  forward
	if (key == GLUT_KEY_PAGE_UP) {
		moveSpeed += 0.03;
	}
	//make ethe  backward
	if (key == GLUT_KEY_PAGE_DOWN) {
		moveSpeed -= 0.03;
		/*if (moveSpeed< 0.01) {
			moveSpeed = 0.01;
		}*/
	}
	//make the  up
	if (key == GLUT_KEY_UP) {
		planeMoveY += 0.2;
		cameraCenterY += 0.2;
		cameraEyeY += 0.2;
	}
	//make the  down
	if (key == GLUT_KEY_DOWN) {
		planeMoveY -= 0.2;
		cameraCenterY -= 0.2;
		cameraEyeY -= 0.2;
	}

	//redraw the new state
	glutPostRedisplay();
}

/************************************************************************

Function:		 mymotion

Description:	 make the plane move through mouse

*************************************************************************/
void mymotion(int x, int y) {

	//judge the position of mouse
	if (x > (windowWidth / 2))
	{
		Right = 1;
		left = 0;
		turnRight = (x - windowWidth / 2)/200;
		gamma = (x - windowWidth / 2) / 20;
	}

	//judge the postion of mouse
	if (x < (windowWidth / 2)) {
		Right = 0;
		left = 1;
		turnLeft = (windowWidth / 2- x ) / 200;
		gamma=(x - windowWidth / 2) / 20;
	}
	
}

/************************************************************************

Function:		 myIdle

Description:	 Updates the animation when idle.

*************************************************************************/
void myIdle() {
	theta += 29;
	cameraEyeX -= moveSpeed;
	cameraEyeZ -= moveSpeed;
	planeMoveX -= moveSpeed;
	planeMoveZ -= moveSpeed;
	cameraCenterX -= moveSpeed;
	cameraCenterZ -= moveSpeed;
	if (Right) {
		planeMoveZ -= turnRight;
		cameraCenterZ -= turnRight;
		cameraEyeZ -= turnRight;
		planeMoveX += turnRight;
		cameraCenterX += turnRight;
		cameraEyeX += turnRight;
	}
	if (left) {
		planeMoveZ += turnLeft;
		planeMoveX -= turnLeft;
		cameraCenterZ += turnLeft;
		cameraCenterX -= turnLeft;
		cameraEyeZ += turnLeft;
		cameraEyeX -= turnLeft;
	}
	sunlight += 0.5;
	if (sunlight >= 0) {
		sunlight = -50;
	}
	randColor = (GLfloat)(rand()) / (RAND_MAX);
	if (airdropOn) {
		fallAir -= 0.5;
		if (fallAir <= 0) {
			fallAir = 0;
		}
	}
	rainLoop -= 0.5;
	if (rainLoop == -20) {
		rainLoop = 0;
	}

	//redraw the new state
	glutPostRedisplay(); 
}

/************************************************************************

Function:		initializeGL

Description:	initialize the factor

*************************************************************************/
void initializeGL(void) {
	//enable the depth test
	//glEnable(GL_DEPTH_TEST);
	//enable the smooth 
	glEnable(GL_SMOOTH);
	//set the background to be black
	glClearColor(0, 0, 0, 1.0);
	GLfloat ambientLight[] = { 0.0, 0.0, 0.0, 1.0 };  // relying on global ambient
	GLfloat diffuseLight[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specularLight[] = { 1.0, 1.0, 1.0, 1.0 };

	//  the global ambient light level
	GLfloat globalAmbientLight[] = { 0.4, 0.4, 0.4, 1.0 };

	// set the global ambient light level
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

	// define the color and intensity for light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, diffuseLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, specularLight);

	// enable lighting 
	glEnable(GL_LIGHTING);
	// enable light 0
	glEnable(GL_LIGHT0);


	// turn on depth testing so that polygons are drawn in the correct order
	glEnable(GL_DEPTH_TEST);

	// make sure the normals are unit vectors
	glEnable(GL_NORMALIZE);
}

/************************************************************************

Function:		myReshape

Description:	reshape the window

*************************************************************************/

void myReshape(int newWidth, int newHeight) {
	// update the new width
	windowWidth = newWidth;
	// update the new height
	windowHeight = newHeight;
	//set the view port
	glViewport(0, 0, newWidth, newHeight);
	// change into projection mode so that we can change the camera properties
	glMatrixMode(GL_PROJECTION);
	// load the identity matrix into the projection matrix
	glLoadIdentity();
	// gluPerspective(fovy, aspect, near, far)
	gluPerspective(60, (float)newWidth/ (float)newHeight, 0.1, 1000);
	// change into model-view mode so that we can change the object positions
	glMatrixMode(GL_MODELVIEW);

}

/************************************************************************

Function:		print

Description:	the function tells the user how to use the application

*************************************************************************/
void print() {
	printf("Scene Controls\n");
	printf("------------------\n\n");
	printf("w:\ttoggle wire frame and slid rendering\n");
	printf("f:\ttoggle fullscreen\n");
	printf("w:\ttoggle wire frame and slid rendering\n");
	printf("s:\ttoggle grid and sea/sky\n");
	printf("b:\ttoggle fog\n");
	printf("m:\ttoggle mountain\n");
	printf("a:\ttoggle airdrop\n");
	printf("r:\ttoggle rain\n");
	printf("e:\ttoggle snow\n\n");
	printf("Camera Controls\n");
	printf("-------------------\n\n");
	printf("MOUSE\tLEFT: \tfly to left\n");
	printf("MOUSE\tRIGHT: \tfly to right\n");
	printf("KEY\tUP: \tmove up\n");
	printf("KEY\tDOWN: \tmove down\n");
	printf("PAGE\tUP: \tforwards\n");
	printf("PAGE\tUP: \tforwards\n");
	printf("PAGE\tDOWN: \tbackwards");

}

/************************************************************************

Function:		main

Description:	main fucction of the program

*************************************************************************/
int main(int argc, char** argv) {
	// initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	// set window position on screen
	glutInitWindowPosition(50, 50);
	// set window size
	glutInitWindowSize(windowWidth, windowHeight);
	// open the screen window
	glutCreateWindow("Final Project");	

	// register redraw function
	glutDisplayFunc(myDisplay);	
	//register keyboard function	
	glutKeyboardFunc(myKeyboard);
	glutPassiveMotionFunc(mymotion);
	glutReshapeFunc(myReshape);
	//register special keyboard function
	glutSpecialFunc(specialKeyboard);
	// register the idle function
	glutIdleFunc(myIdle);
	//initialize the rendering context
	initializeGL();
	//use print function
	print();
	skyseaTexture();
	// go into a perpetual loop
	glutMainLoop();
}