#include "Logo.h"
#include "GraphicsGX.h"
#include <math.h>

namespace menu {

#define LOGO_N_X1 30
#define LOGO_N_X2 13
#define LOGO_N_Y1 30
#define LOGO_N_Y2  5
#define LOGO_N_Z1 30
#define LOGO_N_Z2 13

// 'N' logo vertex data
s8 N_verts[] ATTRIBUTE_ALIGN (32) =
{ // x y z
  -LOGO_N_X1, -LOGO_N_Y1,  LOGO_N_Z1,		// 0 (side A, XY plane, Z=LOGO_N_Z1)
  -LOGO_N_X2, -LOGO_N_Y1,  LOGO_N_Z1,		// 1		6 7   8 9
   LOGO_N_X2, -LOGO_N_Y1,  LOGO_N_Z1,		// 2		  5    
   LOGO_N_X1, -LOGO_N_Y1,  LOGO_N_Z1,		// 3		      4  
   LOGO_N_X2, -LOGO_N_Y2,  LOGO_N_Z1,		// 4		0 1   2 3
  -LOGO_N_X2,  LOGO_N_Y2,  LOGO_N_Z1,		// 5
  -LOGO_N_X1,  LOGO_N_Y1,  LOGO_N_Z1,		// 6
  -LOGO_N_X2,  LOGO_N_Y1,  LOGO_N_Z1,		// 7
   LOGO_N_X2,  LOGO_N_Y1,  LOGO_N_Z1,		// 8
   LOGO_N_X1,  LOGO_N_Y1,  LOGO_N_Z1,		// 9
   LOGO_N_Z1, -LOGO_N_Y1,  LOGO_N_X1,		// 10 (side B, -ZY plane, X=LOGO_N_Z1)
   LOGO_N_Z1, -LOGO_N_Y1,  LOGO_N_X2,		// 11		6 7   8 9
   LOGO_N_Z1, -LOGO_N_Y1, -LOGO_N_X2,		// 12		  5    
   LOGO_N_Z1, -LOGO_N_Y1, -LOGO_N_X1,		// 13		      4  
   LOGO_N_Z1, -LOGO_N_Y2, -LOGO_N_X2,		// 14		0 1   2 3
   LOGO_N_Z1,  LOGO_N_Y2,  LOGO_N_X2,		// 15
   LOGO_N_Z1,  LOGO_N_Y1,  LOGO_N_X1,		// 16
   LOGO_N_Z1,  LOGO_N_Y1,  LOGO_N_X2,		// 17
   LOGO_N_Z1,  LOGO_N_Y1, -LOGO_N_X2,		// 18
   LOGO_N_Z1,  LOGO_N_Y1, -LOGO_N_X1,		// 19
   LOGO_N_X1, -LOGO_N_Y1, -LOGO_N_Z1,		// 20 (side C, -XY plane, Z=-LOGO_N_Z1)
   LOGO_N_X2, -LOGO_N_Y1, -LOGO_N_Z1,		// 21		6 7   8 9
  -LOGO_N_X2, -LOGO_N_Y1, -LOGO_N_Z1,		// 22		  5    
  -LOGO_N_X1, -LOGO_N_Y1, -LOGO_N_Z1,		// 23		      4  
  -LOGO_N_X2, -LOGO_N_Y2, -LOGO_N_Z1,		// 24		0 1   2 3
   LOGO_N_X2,  LOGO_N_Y2, -LOGO_N_Z1,		// 25
   LOGO_N_X1,  LOGO_N_Y1, -LOGO_N_Z1,		// 26
   LOGO_N_X2,  LOGO_N_Y1, -LOGO_N_Z1,		// 27
  -LOGO_N_X2,  LOGO_N_Y1, -LOGO_N_Z1,		// 28
  -LOGO_N_X1,  LOGO_N_Y1, -LOGO_N_Z1,		// 29
  -LOGO_N_Z1, -LOGO_N_Y1, -LOGO_N_X1,		// 30 (side D, ZY plane, X=-LOGO_N_Z1)
  -LOGO_N_Z1, -LOGO_N_Y1, -LOGO_N_X2,		// 31		6 7   8 9
  -LOGO_N_Z1, -LOGO_N_Y1,  LOGO_N_X2,		// 32		  5    
  -LOGO_N_Z1, -LOGO_N_Y1,  LOGO_N_X1,		// 33		      4  
  -LOGO_N_Z1, -LOGO_N_Y2,  LOGO_N_X2,		// 34		0 1   2 3
  -LOGO_N_Z1,  LOGO_N_Y2, -LOGO_N_X2,		// 35
  -LOGO_N_Z1,  LOGO_N_Y1, -LOGO_N_X1,		// 36
  -LOGO_N_Z1,  LOGO_N_Y1, -LOGO_N_X2,		// 37
  -LOGO_N_Z1,  LOGO_N_Y1,  LOGO_N_X2,		// 38
  -LOGO_N_Z1,  LOGO_N_Y1,  LOGO_N_X1,		// 39
  -LOGO_N_X2,  LOGO_N_Y1,  LOGO_N_Z2,		// 40,7A (top, XZ plane, Y=LOGO_N_Y1)
   LOGO_N_X2,  LOGO_N_Y1,  LOGO_N_Z2,		// 41,7B		
   LOGO_N_X2,  LOGO_N_Y1, -LOGO_N_Z2,		// 42,7C		  7D 7C
  -LOGO_N_X2,  LOGO_N_Y1, -LOGO_N_Z2,		// 43,7D		  7A 7B  
  -LOGO_N_X2,  LOGO_N_Y2,  LOGO_N_Z2,		// 44,5A (upper-middle, XZ plane, Y=LOGO_N_Y2)
   LOGO_N_X2,  LOGO_N_Y2,  LOGO_N_Z2,		// 45,5B		
   LOGO_N_X2,  LOGO_N_Y2, -LOGO_N_Z2,		// 46,5C		  5D 5C
  -LOGO_N_X2,  LOGO_N_Y2, -LOGO_N_Z2,		// 47,5D		  5A 5B  
  -LOGO_N_X2, -LOGO_N_Y2,  LOGO_N_Z2,		// 48,4D (lower-middle, XZ plane, Y=-LOGO_N_Y2)
   LOGO_N_X2, -LOGO_N_Y2,  LOGO_N_Z2,		// 49,4A		
   LOGO_N_X2, -LOGO_N_Y2, -LOGO_N_Z2,		// 50,4B		  4C 4B
  -LOGO_N_X2, -LOGO_N_Y2, -LOGO_N_Z2,		// 51,4C		  4D 4A  
  -LOGO_N_X2, -LOGO_N_Y1,  LOGO_N_Z2,		// 52,1A (bottom, XZ plane, Y=-LOGO_N_Y1)
   LOGO_N_X2, -LOGO_N_Y1,  LOGO_N_Z2,		// 53,1B		
   LOGO_N_X2, -LOGO_N_Y1, -LOGO_N_Z2,		// 54,1C		  1D 1C
  -LOGO_N_X2, -LOGO_N_Y1, -LOGO_N_Z2,		// 55,1D		  1A 1B  
};

#define LOGO_M_X0  0
#define LOGO_M_X1  7
#define LOGO_M_X2 15
#define LOGO_M_X3 30
#define LOGO_M_Y0  0
#define LOGO_M_Y1  8
#define LOGO_M_Y2 15
#define LOGO_M_Y3 30
#define LOGO_M_Z0  0
#define LOGO_M_Z1  7
#define LOGO_M_Z2 15
#define LOGO_M_Z3 30

// 'N' logo vertex data
s8 M_verts[] ATTRIBUTE_ALIGN (32) =
{ // x y z
	-LOGO_M_X3, -LOGO_M_Y3,  LOGO_M_Z3,		//  0, 0 (side A, XY plane, Z=LOGO_M_Z3)
	-LOGO_M_X2, -LOGO_M_Y3,  LOGO_M_Z3,		//  1, 1		9 A    B C
	 LOGO_M_X2, -LOGO_M_Y3,  LOGO_M_Z3,		//  2, 2			8
	 LOGO_M_X3, -LOGO_M_Y3,  LOGO_M_Z3,		//  3, 3		  6    7
	-LOGO_M_X1,  LOGO_M_Y0,  LOGO_M_Z3,		//  4, 4		    45  
	 LOGO_M_X1,  LOGO_M_Y0,  LOGO_M_Z3,		//  5, 5		0 1    2 3
	-LOGO_M_X2,  LOGO_M_Y1,  LOGO_M_Z3,		//  6, 6
	 LOGO_M_X2,  LOGO_M_Y1,  LOGO_M_Z3,		//  7, 7
	 LOGO_M_X0,  LOGO_M_Y2,  LOGO_M_Z3,		//  8, 8
	-LOGO_M_X3,  LOGO_M_Y3,  LOGO_M_Z3,		//  9, 9
	-LOGO_M_X2,  LOGO_M_Y3,  LOGO_M_Z3,		// 10, A
	 LOGO_M_X2,  LOGO_M_Y3,  LOGO_M_Z3,		// 11, B
	 LOGO_M_X3,  LOGO_M_Y3,  LOGO_M_Z3,		// 12, C

	 LOGO_M_Z3, -LOGO_M_Y3,  LOGO_M_X3, 	// 13, 0 (side B, -ZY plane, X=LOGO_M_Z3)
	 LOGO_M_Z3,	-LOGO_M_Y3,  LOGO_M_X2, 	// 14, 1		9 A    B C
	 LOGO_M_Z3,	-LOGO_M_Y3, -LOGO_M_X2, 	// 15, 2			8
	 LOGO_M_Z3,	-LOGO_M_Y3, -LOGO_M_X3, 	// 16, 3		  6    7
	 LOGO_M_Z3,	 LOGO_M_Y0,  LOGO_M_X1, 	// 17, 4		    45  
	 LOGO_M_Z3,	 LOGO_M_Y0, -LOGO_M_X1, 	// 18, 5		0 1    2 3
	 LOGO_M_Z3,  LOGO_M_Y1,  LOGO_M_X2,		// 19, 6
	 LOGO_M_Z3,	 LOGO_M_Y1, -LOGO_M_X2, 	// 20, 7
	 LOGO_M_Z3,	 LOGO_M_Y2, -LOGO_M_X0, 	// 21, 8
	 LOGO_M_Z3,	 LOGO_M_Y3,  LOGO_M_X3, 	// 22, 9
	 LOGO_M_Z3,	 LOGO_M_Y3,  LOGO_M_X2, 	// 23, A
	 LOGO_M_Z3,	 LOGO_M_Y3, -LOGO_M_X2, 	// 24, B
	 LOGO_M_Z3,	 LOGO_M_Y3, -LOGO_M_X3, 	// 25, C

	 LOGO_M_X3, -LOGO_M_Y3, -LOGO_M_Z3,		// 26, 0 (side C, -XY plane, Z=-LOGO_M_Z3)
	 LOGO_M_X2, -LOGO_M_Y3, -LOGO_M_Z3,		// 27, 1		9 A    B C
	-LOGO_M_X2, -LOGO_M_Y3, -LOGO_M_Z3,		// 28, 2			8
	-LOGO_M_X3, -LOGO_M_Y3, -LOGO_M_Z3,		// 29, 3		  6    7
	 LOGO_M_X1,  LOGO_M_Y0, -LOGO_M_Z3,		// 30, 4		    45  
	-LOGO_M_X1,  LOGO_M_Y0, -LOGO_M_Z3,		// 31, 5		0 1    2 3
	 LOGO_M_X2,  LOGO_M_Y1, -LOGO_M_Z3,		// 32, 6
	-LOGO_M_X2,  LOGO_M_Y1, -LOGO_M_Z3,		// 33, 7
	-LOGO_M_X0,  LOGO_M_Y2, -LOGO_M_Z3,		// 34, 8
	 LOGO_M_X3,  LOGO_M_Y3, -LOGO_M_Z3,		// 35, 9
	 LOGO_M_X2,  LOGO_M_Y3, -LOGO_M_Z3,		// 36, A
	-LOGO_M_X2,  LOGO_M_Y3, -LOGO_M_Z3,		// 37, B
	-LOGO_M_X3,  LOGO_M_Y3, -LOGO_M_Z3,		// 38, C

	-LOGO_M_Z3, -LOGO_M_Y3, -LOGO_M_X3, 	// 39, 0 (side D, ZY plane, X=-LOGO_M_Z3)
	-LOGO_M_Z3,	-LOGO_M_Y3, -LOGO_M_X2, 	// 40, 1		9 A    B C
	-LOGO_M_Z3,	-LOGO_M_Y3,  LOGO_M_X2, 	// 41, 2			8
	-LOGO_M_Z3,	-LOGO_M_Y3,  LOGO_M_X3, 	// 42, 3		  6    7
	-LOGO_M_Z3,	 LOGO_M_Y0, -LOGO_M_X1, 	// 43, 4		    45  
	-LOGO_M_Z3,	 LOGO_M_Y0,  LOGO_M_X1, 	// 44, 5		0 1    2 3
	-LOGO_M_Z3,  LOGO_M_Y1, -LOGO_M_X2,		// 45, 6
	-LOGO_M_Z3,	 LOGO_M_Y1,  LOGO_M_X2, 	// 46, 7
	-LOGO_M_Z3,	 LOGO_M_Y2,  LOGO_M_X0, 	// 47, 8
	-LOGO_M_Z3,	 LOGO_M_Y3, -LOGO_M_X3, 	// 48, 9
	-LOGO_M_Z3,	 LOGO_M_Y3, -LOGO_M_X2, 	// 49, A
	-LOGO_M_Z3,	 LOGO_M_Y3,  LOGO_M_X2, 	// 50, B
	-LOGO_M_Z3,	 LOGO_M_Y3,  LOGO_M_X3, 	// 51, C

	-LOGO_M_X2,  LOGO_M_Y3,  LOGO_M_Z2,		// 52,9A (top, XZ plane, Y=LOGO_M_Y3)
	 LOGO_M_X2,  LOGO_M_Y3,  LOGO_M_Z2,		// 53,9B		
	 LOGO_M_X2,  LOGO_M_Y3, -LOGO_M_Z2,		// 54,9C		  9D 9C
	-LOGO_M_X2,  LOGO_M_Y3, -LOGO_M_Z2,		// 55,9D		  9A 9B  

	 LOGO_M_X0,  LOGO_M_Y2,  LOGO_M_Z2,		// 56,8A (upper-middle, XZ plane, Y=LOGO_M_Y2)
	 LOGO_M_X2,  LOGO_M_Y2,  LOGO_M_Z0,		// 57,8B		       8C
	 LOGO_M_X0,  LOGO_M_Y2, -LOGO_M_Z2,		// 58,8C	        8D    8B
	-LOGO_M_X2,  LOGO_M_Y2,  LOGO_M_Z0,		// 59,8D	           8A     

	-LOGO_M_X2,  LOGO_M_Y1,  LOGO_M_Z2,		// 60,6A (center-middle, XZ plane, Y=LOGO_M_Y1)
	 LOGO_M_X2,  LOGO_M_Y1,  LOGO_M_Z2,		// 61,6B		
	 LOGO_M_X2,  LOGO_M_Y1, -LOGO_M_Z2,		// 62,6C		  6D 6C
	-LOGO_M_X2,  LOGO_M_Y1, -LOGO_M_Z2,		// 63,6D		  6A 6B  

	-LOGO_M_X1,  LOGO_M_Y0,  LOGO_M_Z2,		// 64,4A (lower-middle, XZ plane, Y=LOGO_M_Y0)
	 LOGO_M_X1,  LOGO_M_Y0,  LOGO_M_Z2,		// 65,4B		
	 LOGO_M_X2,  LOGO_M_Y0,  LOGO_M_Z1,		// 66,4C		  4F 4E
	 LOGO_M_X2,  LOGO_M_Y0, -LOGO_M_Z1,		// 67,4D	   4G       4D 
	 LOGO_M_X1,  LOGO_M_Y0, -LOGO_M_Z2,		// 68,4E       4H       4C
	-LOGO_M_X1,  LOGO_M_Y0, -LOGO_M_Z2,		// 69,4F		  4A 4B
	-LOGO_M_X2,  LOGO_M_Y0, -LOGO_M_Z1,		// 70,4G		  
	-LOGO_M_X2,  LOGO_M_Y0,  LOGO_M_Z1,		// 71,4H		    

	-LOGO_M_X2, -LOGO_M_Y3,  LOGO_M_Z2,		// 72,1A (bottom, XZ plane, Y=-LOGO_M_Y3)
	 LOGO_M_X2, -LOGO_M_Y3,  LOGO_M_Z2,		// 73,1B		
	 LOGO_M_X2, -LOGO_M_Y3, -LOGO_M_Z2,		// 74,1C		  1D 1C
	-LOGO_M_X2, -LOGO_M_Y3, -LOGO_M_Z2,		// 75,1D		  1A 1B  
};

// N64 logo color data
u8 logo_colors[] ATTRIBUTE_ALIGN (32) =
{ // r, g, b, a
	  8, 147,  48, 255,		// 0 green
	  1,  29, 169, 255,		// 1 blue
	254,  32,  21, 255,		// 2 orange/red
	255, 192,   1, 255,		// 3 yellow/gold
	230,   1,   1, 255,		// 4 red
	190, 190, 190, 255,		// 4 light gray
};


Logo::Logo()
		: logoMode(LOGO_N),
		  x(0),
		  y(0),
		  size(1),
		  rotateAuto(0),
		  rotateX(0),
		  rotateY(0)
{
	setVisible(false);
}

Logo::~Logo()
{
}

void Logo::setLocation(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

void Logo::setSize(float newSize)
{
	size = newSize;
}

void Logo::setMode(int mode)
{
	logoMode = mode;
}

//#include "ogc/lwp_watchdog.h"

//#define SCROLL_PERIOD 4.0f

void Logo::updateTime(float deltaTime)
{
	//Overload in Component class
	//Add interpolator class & update here?
}

void Logo::drawComponent(Graphics& gfx)
{
	Mtx v, m, mv, tmp;            // view, model, modelview, and perspective matrices
	guVector cam = { 0.0F, 0.0F, 0.0F }, 
		up = {0.0F, 1.0F, 0.0F}, 
		look = {0.0F, 0.0F, -1.0F},
		axisX = {1.0F, 0.0F, 0.0F},
		axisY = {0.0F, 1.0F, 0.0F};
	s8 stickX,stickY;

	guLookAt (v, &cam, &up, &look);
	rotateAuto++;

	u16 pad0 = PAD_ButtonsDown(0);
	if (pad0 & PAD_TRIGGER_Z) logoMode = (logoMode+1) % 2;

	//libOGC was changed such that sticks are now clamped and don't have to be by us
	stickX = PAD_SubStickX(0);
	stickY = PAD_SubStickY(0);
//	if(stickX > 18 || stickX < -18) rotateX += stickX/32;
//	if(stickY > 18 || stickY < -18) rotateY += stickY/32;
	rotateX += stickX/32;
	rotateY += stickY/32;

	// move the logo out in front of us and rotate it
	guMtxIdentity (m);
	guMtxRotAxisDeg (tmp, &axisX, 25);			//change to isometric view
	guMtxConcat (m, tmp, m);
	guMtxRotAxisDeg (tmp, &axisX, 180);			//flip rightside-up
	guMtxConcat (m, tmp, m);
	guMtxRotAxisDeg (tmp, &axisX, -rotateY);
	guMtxConcat (m, tmp, m);
	guMtxRotAxisDeg (tmp, &axisY, rotateX);
	guMtxConcat (m, tmp, m);
	guMtxRotAxisDeg (tmp, &axisY, -rotateAuto);		//slowly rotate logo
	guMtxConcat (m, tmp, m);
	guMtxTransApply (m, m, x, y, z);
	guMtxConcat (v, m, mv);
	// load the modelview matrix into matrix memory
	GX_LoadPosMtxImm (mv, GX_PNMTX0);

	GX_SetCullMode (GX_CULL_BACK); // show only the outside facing quads
	GX_SetZMode(GX_ENABLE,GX_GEQUAL,GX_TRUE);

	// setup the vertex descriptor
	GX_ClearVtxDesc ();
	GX_SetVtxDesc(GX_VA_PTNMTXIDX, GX_PNMTX0);
	GX_SetVtxDesc (GX_VA_POS, GX_INDEX8);
	GX_SetVtxDesc (GX_VA_CLR0, GX_INDEX8);
	
	// setup the vertex attribute table
	GX_SetVtxAttrFmt (GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S8, 0);
	GX_SetVtxAttrFmt (GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	
	// set the array stride
	if(logoMode == LOGO_N)		GX_SetArray (GX_VA_POS, N_verts, 3 * sizeof (s8));
	else if(logoMode == LOGO_M)	GX_SetArray (GX_VA_POS, M_verts, 3 * sizeof (s8));
	GX_SetArray (GX_VA_CLR0, logo_colors, 4 * sizeof (u8));
	
	GX_SetNumChans (1);
	GX_SetNumTexGens (0);
	GX_SetTevOrder (GX_TEVSTAGE0, GX_TEXCOORDNULL, GX_TEXMAP_NULL, GX_COLOR0A0);
	GX_SetTevOp (GX_TEVSTAGE0, GX_PASSCLR);

	if (logoMode == LOGO_N)
	{
		// 'N'
		GX_Begin (GX_QUADS, GX_VTXFMT0, 160);  //40 quads, so 160 verts
		drawQuad ( 0,  6,  7,  1, 0); //Side A, green
		drawQuad ( 7,  4,  2,  5, 0);
		drawQuad ( 2,  8,  9,  3, 0);
		drawQuad (31, 35, 47, 55, 0); //Side A1
		drawQuad (55, 51, 42, 46, 0);
		drawQuad (50, 42, 18, 14, 0);
		drawQuad (10, 16, 17, 11, 1); //Side B, blue
		drawQuad (17, 14, 12, 15, 1);
		drawQuad (12, 18, 19, 13, 1);
		drawQuad ( 1,  5, 44, 52, 1); //Side B1
		drawQuad (52, 48, 43, 47, 1);
		drawQuad (51, 43, 28, 24, 1);
		drawQuad (20, 26, 27, 21, 0); //Side C, green
		drawQuad (27, 24, 22, 25, 0);
		drawQuad (22, 28, 29, 23, 0);
		drawQuad (11, 15, 45, 53, 0); //Side C1
		drawQuad (53, 49, 40, 44, 0);
		drawQuad (48, 40, 38, 34, 0);
		drawQuad (30, 36, 37, 31, 1); //Side D, blue
		drawQuad (37, 34, 32, 35, 1);
		drawQuad (32, 38, 39, 33, 1);
		drawQuad (21, 25, 46, 54, 1); //Side D1
		drawQuad (54, 50, 41, 45, 1);
		drawQuad (49, 41,  8,  4, 1);
		drawQuad ( 6, 38, 40,  7, 3); //Top, yellow
		drawQuad ( 8, 41, 17,  9, 3);
		drawQuad (42, 27, 19, 18, 3);
		drawQuad (37, 29, 28, 43, 3); 
		drawQuad ( 7, 40, 49,  4, 2); //Top, red(green?)
		drawQuad (17, 41, 50, 14, 0);
		drawQuad (27, 42, 51, 24, 2);
		drawQuad (37, 43, 48, 34, 0); 
		drawQuad ( 0,  1, 52, 32, 3); //Bottom, yellow
		drawQuad ( 3, 11, 53,  2, 3);
		drawQuad (13, 21, 54, 12, 3);
		drawQuad (23, 31, 55, 22, 3); 
		drawQuad ( 2, 53, 44,  5, 2); //Bottom, red(green?)
		drawQuad (12, 54, 45, 15, 0);
		drawQuad (22, 55, 46, 25, 2);
		drawQuad (32, 52, 47, 35, 0); 
		GX_End ();
	}
	else if (logoMode == LOGO_M)
	{
		// 'M'
		GX_Begin (GX_QUADS, GX_VTXFMT0, 272);  //68 quads, so 272 verts 40+12+16
		drawQuad ( 0,  9, 10,  1, 4); //Side A, red
		drawQuad ( 6, 10,  8,  4, 4);
		drawQuad ( 4,  8,  8,  5, 4);
		drawQuad ( 5,  8, 11,  7, 4);
		drawQuad ( 2, 11, 12,  3, 4);
		drawQuad (40, 45, 63, 75, 4); //Side A1
		drawQuad (63, 55, 58, 69, 4);
		drawQuad (69, 58, 58, 68, 4);
		drawQuad (68, 58, 54, 62, 4);
		drawQuad (62, 20, 15, 74, 4);

		drawQuad (13, 22, 23, 14, 4); //Side B, red
		drawQuad (19, 23, 21, 17, 4);
		drawQuad (17, 21, 21, 18, 4);
		drawQuad (18, 21, 24, 20, 4);
		drawQuad (15, 24, 25, 16, 4);
		drawQuad ( 1,  6, 60, 72, 4); //Side B1
		drawQuad (52, 59, 71, 60, 4);
		drawQuad (71, 59, 59, 70, 4);
		drawQuad (70, 59, 55, 63, 4);
		drawQuad (75, 63, 33, 28, 4);

		drawQuad (26, 35, 36, 27, 4); //Side C, red
		drawQuad (32, 36, 34, 30, 4);
		drawQuad (30, 34, 34, 31, 4);
		drawQuad (31, 34, 37, 33, 4);
		drawQuad (28, 37, 38, 29, 4);
		drawQuad (14, 19, 61, 73, 4); //Side C1
		drawQuad (61, 53, 56, 65, 4);
		drawQuad (65, 56, 56, 64, 4);
		drawQuad (64, 56, 52, 60, 4);
		drawQuad (72, 60, 46, 41, 4);

		drawQuad (39, 48, 49, 40, 4); //Side D, red
		drawQuad (45, 49, 47, 43, 4);
		drawQuad (43, 47, 47, 44, 4);
		drawQuad (44, 47, 50, 46, 4);
		drawQuad (41, 50, 51, 42, 4);
		drawQuad (27, 32, 62, 74, 4); //Side D1
		drawQuad (62, 54, 57, 67, 4);
		drawQuad (67, 57, 57, 66, 4);
		drawQuad (66, 57, 53, 61, 4);
		drawQuad (73, 61,  7,  2, 4);

		drawQuad (10,  9, 50, 52, 5); //Top, gray
		drawQuad (49, 48, 37, 55, 5);
		drawQuad (36, 35, 24, 54, 5);
		drawQuad (23, 22, 11, 53, 5);

		drawQuad (59, 52, 50, 47, 5); //Top-slanted, gray
		drawQuad (47, 49, 55, 59, 5);
		drawQuad (58, 55, 37, 34, 5);
		drawQuad (34, 36, 54, 58, 5);
		drawQuad (57, 54, 24, 21, 5);
		drawQuad (21, 23, 53, 57, 5);
		drawQuad (56, 53, 11,  8, 5);
		drawQuad ( 8, 10, 52, 56, 5);

		drawQuad ( 0,  1, 72, 41, 5); //Bottom, gray
		drawQuad (39, 40, 75, 28, 5);
		drawQuad (26, 27, 74, 15, 5);
		drawQuad (13, 14, 73,  2, 5);

		drawQuad ( 6,  4, 64, 60, 5); //Bottom-slanted, gray
		drawQuad ( 4,  5, 65, 64, 5);
		drawQuad ( 5,  7, 61, 65, 5);

		drawQuad (19, 17, 66, 61, 5);
		drawQuad (17, 18, 67, 66, 5);
		drawQuad (18, 20, 62, 67, 5);

		drawQuad (32, 30, 68, 62, 5);
		drawQuad (30, 31, 69, 68, 5);
		drawQuad (31, 33, 63, 69, 5);

		drawQuad (45, 43, 70, 63, 5);
		drawQuad (43, 44, 71, 70, 5);
		drawQuad (44, 46, 60, 71, 5);
		GX_End ();
	}
		
	gfx.drawInit();
}

void Logo::drawQuad(u8 v0, u8 v1, u8 v2, u8 v3, u8 c)
{
	// draws a quad from 4 vertex idx and one color idx
	// one 8bit position idx
	GX_Position1x8 (v0);
	// one 8bit color idx
	GX_Color1x8 (c);
	GX_Position1x8 (v1);
	GX_Color1x8 (c);
	GX_Position1x8 (v2);
	GX_Color1x8 (c);
	GX_Position1x8 (v3);
	GX_Color1x8 (c);
}

} //namespace menu 