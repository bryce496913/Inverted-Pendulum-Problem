#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {

	const int no_of_theta_rules = 25;
	const int no_of_x_rules = 25;
	int i;

	for (i = 0; i < no_of_theta_rules; i++) {
		fl->rules[i].inp_index[0] = in_theta;
		fl->rules[i].inp_index[1] = in_theta_dot;
	}

  // Rule 1
	fl->rules[0].inp_fuzzy_set[0] = in_ns;
	fl->rules[0].inp_fuzzy_set[1] = in_ns;
	fl->rules[0].out_fuzzy_set = out_ns;

  // Rule 2
	fl->rules[1].inp_fuzzy_set[0] = in_nl;
	fl->rules[1].inp_fuzzy_set[1] = in_ns;
	fl->rules[1].out_fuzzy_set = out_nm;

  // Rule 3
	fl->rules[2].inp_fuzzy_set[0] = in_nl;
	fl->rules[2].inp_fuzzy_set[1] = in_ze;
	fl->rules[2].out_fuzzy_set = out_nl;

  // Rule 4
  fl->rules[3].inp_fuzzy_set[0] = in_nl;
  fl->rules[3].inp_fuzzy_set[1] = in_ps;
  fl->rules[3].out_fuzzy_set = out_nm;

  // Rule 5
	fl->rules[4].inp_fuzzy_set[0] = in_nl;
	fl->rules[4].inp_fuzzy_set[1] = in_pl;
	fl->rules[4].out_fuzzy_set = out_ns;

  // Rule 6
	fl->rules[5].inp_fuzzy_set[0] = in_ns;
	fl->rules[5].inp_fuzzy_set[1] = in_nl;
	fl->rules[5].out_fuzzy_set = out_ns;

  // Rule 7
  fl->rules[6].inp_fuzzy_set[0] = in_ns;
  fl->rules[6].inp_fuzzy_set[1] = in_ns;
  fl->rules[6].out_fuzzy_set = out_nvl;

  // Rule 8
	fl->rules[7].inp_fuzzy_set[0] = in_ns;
	fl->rules[7].inp_fuzzy_set[1] = in_ze;
	fl->rules[7].out_fuzzy_set = out_ze;

  // Rule 9
	fl->rules[8].inp_fuzzy_set[0] = in_ns;
	fl->rules[8].inp_fuzzy_set[1] = in_ps;
	fl->rules[8].out_fuzzy_set = out_nvl;

  // Rule 10
	fl->rules[9].inp_fuzzy_set[0] = in_ns;
	fl->rules[9].inp_fuzzy_set[1] = in_pl;
	fl->rules[9].out_fuzzy_set = out_ns;

  // Rule 11
	fl->rules[10].inp_fuzzy_set[0] = in_ze;
	fl->rules[10].inp_fuzzy_set[1] = in_nl;
	fl->rules[10].out_fuzzy_set = out_nl;

  // Rule 12
	fl->rules[11].inp_fuzzy_set[0] = in_ze;
	fl->rules[11].inp_fuzzy_set[1] = in_ns;
	fl->rules[11].out_fuzzy_set = out_ns;

  // Rule 13
	fl->rules[12].inp_fuzzy_set[0] = in_ze;
	fl->rules[12].inp_fuzzy_set[1] = in_ze;
	fl->rules[12].out_fuzzy_set = out_ze;

  // Rule 14
	fl->rules[13].inp_fuzzy_set[0] = in_ze;
	fl->rules[13].inp_fuzzy_set[1] = in_ps;
	fl->rules[13].out_fuzzy_set = out_ps;

  // Rule 15
	fl->rules[14].inp_fuzzy_set[0] = in_ze;
	fl->rules[14].inp_fuzzy_set[1] = in_pl;
	fl->rules[14].out_fuzzy_set = out_ps;

  // Rule 16
  fl->rules[15].inp_fuzzy_set[0] = in_ps;
  fl->rules[15].inp_fuzzy_set[1] = in_nl;
  fl->rules[15].out_fuzzy_set = out_nm;

  // Rule 17
	fl->rules[16].inp_fuzzy_set[0] = in_ps;
	fl->rules[16].inp_fuzzy_set[1] = in_ns;
	fl->rules[16].out_fuzzy_set = out_ns;

  // Rule 18
	fl->rules[17].inp_fuzzy_set[0] = in_ps;
	fl->rules[17].inp_fuzzy_set[1] = in_ze;
	fl->rules[17].out_fuzzy_set = out_ps;

  // Rule 19
	fl->rules[18].inp_fuzzy_set[0] = in_ps;
	fl->rules[18].inp_fuzzy_set[1] = in_ps;
	fl->rules[18].out_fuzzy_set = out_ps;


  // Rule 20
  fl->rules[19].inp_fuzzy_set[0] = in_ps;
  fl->rules[19].inp_fuzzy_set[1] = in_pl;
  fl->rules[19].out_fuzzy_set = out_pm;

  // Rule 21
  fl->rules[20].inp_fuzzy_set[0] = in_pl;
  fl->rules[20].inp_fuzzy_set[1] = in_nl;
  fl->rules[20].out_fuzzy_set = out_ns;

  // Rule 22
  fl->rules[21].inp_fuzzy_set[0] = in_pl;
  fl->rules[21].inp_fuzzy_set[1] = in_ns;
  fl->rules[21].out_fuzzy_set = out_ns;

  // Rule 23
	fl->rules[22].inp_fuzzy_set[0] = in_pl;
	fl->rules[22].inp_fuzzy_set[1] = in_ze;
	fl->rules[22].out_fuzzy_set = out_ps;

  // Rule 24
	fl->rules[23].inp_fuzzy_set[0] = in_pl;
	fl->rules[23].inp_fuzzy_set[1] = in_ps;
	fl->rules[23].out_fuzzy_set = out_pm;

	fl->rules[24].inp_fuzzy_set[0] = in_pl;
	fl->rules[24].inp_fuzzy_set[1] = in_pl;
	fl->rules[24].out_fuzzy_set = out_pl;

  // Remaining 25 symmetric rules
	for (i = 0; i < no_of_x_rules; i++) {
		fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
		fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
	}

  // Rule 26
	fl->rules[25].inp_fuzzy_set[0] = in_ns;
	fl->rules[25].inp_fuzzy_set[1] = in_pl;
	fl->rules[25].out_fuzzy_set = out_ze;

  // Rule 27
  fl->rules[26].inp_fuzzy_set[0] = in_ns;
  fl->rules[26].inp_fuzzy_set[1] = in_pl;
  fl->rules[26].out_fuzzy_set = out_ns;

  // Rule 28
  fl->rules[27].inp_fuzzy_set[0] = in_ze;
  fl->rules[27].inp_fuzzy_set[1] = in_pl;
  fl->rules[27].out_fuzzy_set = out_ps;

  // Rule 29
  fl->rules[28].inp_fuzzy_set[0] = in_ps;
  fl->rules[28].inp_fuzzy_set[1] = in_pl;
  fl->rules[28].out_fuzzy_set = out_pm;

  // Rule 30
  fl->rules[29].inp_fuzzy_set[0] = in_pl;
  fl->rules[29].inp_fuzzy_set[1] = in_pl;
  fl->rules[29].out_fuzzy_set = out_pl;

  // Rule 31
  fl->rules[30].inp_fuzzy_set[0] = in_pl;
  fl->rules[30].inp_fuzzy_set[1] = in_ps;
  fl->rules[30].out_fuzzy_set = out_pm;

  // Rule 32
  fl->rules[31].inp_fuzzy_set[0] = in_pl;
  fl->rules[31].inp_fuzzy_set[1] = in_ze;
  fl->rules[31].out_fuzzy_set = out_ps;

  // Rule 33
  fl->rules[32].inp_fuzzy_set[0] = in_pl;
  fl->rules[32].inp_fuzzy_set[1] = in_ns;
  fl->rules[32].out_fuzzy_set = out_ns;

  // Rule 34
  fl->rules[33].inp_fuzzy_set[0] = in_pl;
  fl->rules[33].inp_fuzzy_set[1] = in_nl;
  fl->rules[33].out_fuzzy_set = out_ns;

  // Rule 35
  fl->rules[34].inp_fuzzy_set[0] = in_ps;
  fl->rules[34].inp_fuzzy_set[1] = in_nl;
  fl->rules[34].out_fuzzy_set = out_nm;

  // Rule 36
	fl->rules[35].inp_fuzzy_set[0] = in_ps;
	fl->rules[35].inp_fuzzy_set[1] = in_ns;
	fl->rules[35].out_fuzzy_set = out_ns;

  // Rule 37
  fl->rules[36].inp_fuzzy_set[0] = in_ps;
  fl->rules[36].inp_fuzzy_set[1] = in_ze;
  fl->rules[36].out_fuzzy_set = out_ps;

  // Rule 38
  fl->rules[37].inp_fuzzy_set[0] = in_ps;
  fl->rules[37].inp_fuzzy_set[1] = in_ps;
  fl->rules[37].out_fuzzy_set = out_ps;

  // Rule 39
  fl->rules[38].inp_fuzzy_set[0] = in_ps;
  fl->rules[38].inp_fuzzy_set[1] = in_pl;
  fl->rules[38].out_fuzzy_set = out_pm;

  // Rule 40
  fl->rules[39].inp_fuzzy_set[0] = in_ze;
  fl->rules[39].inp_fuzzy_set[1] = in_nl;
  fl->rules[39].out_fuzzy_set = out_nl;

  // Rule 41
  fl->rules[40].inp_fuzzy_set[0] = in_ze;
  fl->rules[40].inp_fuzzy_set[1] = in_ns;
  fl->rules[40].out_fuzzy_set = out_nl;

  // Rule 42
  fl->rules[41].inp_fuzzy_set[0] = in_ze;
  fl->rules[41].inp_fuzzy_set[1] = in_ze;
  fl->rules[41].out_fuzzy_set = out_ze;

  // Rule 43
  fl->rules[42].inp_fuzzy_set[0] = in_ze;
  fl->rules[42].inp_fuzzy_set[1] = in_ps;
  fl->rules[42].out_fuzzy_set = out_ps;

  // Rule 44
  fl->rules[43].inp_fuzzy_set[0] = in_ze;
  fl->rules[43].inp_fuzzy_set[1] = in_pl;
  fl->rules[43].out_fuzzy_set = out_ps;

  // Rule 45
	fl->rules[44].inp_fuzzy_set[0] = in_ns;
	fl->rules[44].inp_fuzzy_set[1] = in_nl;
	fl->rules[44].out_fuzzy_set = out_nl;

  // Rule 46
  fl->rules[45].inp_fuzzy_set[0] = in_ns;
  fl->rules[45].inp_fuzzy_set[1] = in_ns;
  fl->rules[45].out_fuzzy_set = out_nvl;

  // Rule 47
  fl->rules[46].inp_fuzzy_set[0] = in_ns;
  fl->rules[46].inp_fuzzy_set[1] = in_ze;
  fl->rules[46].out_fuzzy_set = out_nl;

  // Rule 48
	fl->rules[47].inp_fuzzy_set[0] = in_nl;
	fl->rules[47].inp_fuzzy_set[1] = in_pl;
	fl->rules[47].out_fuzzy_set = out_ns;

  // Rule 49
  fl->rules[48].inp_fuzzy_set[0] = in_ns;
  fl->rules[48].inp_fuzzy_set[1] = in_pl;
  fl->rules[48].out_fuzzy_set = out_ns;

  // Rule 50
	fl->rules[49].inp_fuzzy_set[0] = in_ns;
	fl->rules[49].inp_fuzzy_set[1] = in_pl;
	fl->rules[49].out_fuzzy_set = out_ze;

}


void initMembershipFunctions(fuzzy_system_rec *fl) {

  // Input 1 (INPUT_X)
	fl->inp_mem_fns[in_x][in_nl] = init_trapz(-4,-3,-2,-1, left_trapezoid);
	fl->inp_mem_fns[in_x][in_ns] = init_trapz(-2.5,-2,-0.5,0, regular_trapezoid);
	fl->inp_mem_fns[in_x][in_ze] = init_trapz(-1.5,-1,1,1.5, regular_trapezoid);
	fl->inp_mem_fns[in_x][in_ps] = init_trapz(0,0.5,2,2.5, regular_trapezoid);
  fl->inp_mem_fns[in_x][in_pl] = init_trapz(2,3,4,4, right_trapezoid);

	fl->inp_mem_fns[in_x_dot][in_nl] = init_trapz(-4,-3,-2,-1,left_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ns] = init_trapz(-3,-2,-1,0,regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ze] = init_trapz(-2,-1,1,2,regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_ps] = init_trapz(0,1,2,3,regular_trapezoid);
	fl->inp_mem_fns[in_x_dot][in_pl] = init_trapz(2,3,4,4,right_trapezoid);

	// Input 2 (INPUT_Y)
	fl->inp_mem_fns[in_theta][in_nl] = init_trapz(-20,-15,-10,-7, left_trapezoid);
	fl->inp_mem_fns[in_theta][in_ns] = init_trapz(-2.5,-2,-0.5,0, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_ze] = init_trapz(-1.5,-1,1,1.5, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_ps] = init_trapz(0,0.5,2,2.5, regular_trapezoid);
	fl->inp_mem_fns[in_theta][in_pl] = init_trapz(7,10,15,20, right_trapezoid);

	fl->inp_mem_fns[in_theta_dot][in_nl] = init_trapz(-20,-15,-10,-7, left_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz(5,8,12,15, right_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_ze] = init_trapz(-2,-1,1,2,regular_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_ps] = init_trapz(0,1,2,3,regular_trapezoid);
	fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz(7,10,15,20, right_trapezoid);

}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 50;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;

	 coefficient_A = 4.5;
	 coefficient_B = 0.7;
	 coefficient_C = 0.6;
	 coefficient_D = 0.5;

	 // Output values
	 fl->output_values[out_nvl] = -150.0; //was 150
   fl->output_values[out_nl] = -80.0;
   fl->output_values[out_nm] = -60.0;
   fl->output_values[out_ns] = -55.0;
   fl->output_values[out_ze] = 0.0;
   fl->output_values[out_ps] = 25.0;
   fl->output_values[out_pm] = 60.0;
   fl->output_values[out_pl] = 80.0;
   fl->output_values[out_pvl] = 150.0;


   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {

   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {

      case regular_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 1.0/(trz.c - trz.d);
         	 break;

      case left_trapezoid:
         	 trz.r_slope = 1.0/(trz.a - trz.b);
         	 trz.l_slope = 0.0;
         	 break;

      case right_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 0.0;
         	 break;
   }  /* end switch  */

   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {

      case left_trapezoid:
         	 if (x <= trz.a)
         	    return 1.0;
         	 if (x >= trz.b)
         	    return 0.0;
         	 /* a < x < b */
         	 return trz.r_slope * (x - trz.b);


      case right_trapezoid:
         	 if (x <= trz.a)
         	    return 0.0;
         	 if (x >= trz.b)
         	    return 1.0;
         	 /* a < x < b */
         	 return trz.l_slope * (x - trz.a);

      case regular_trapezoid:
         	 if ((x <= trz.a) || (x >= trz.d))
         	    return 0.0;
         	 if ((x >= trz.b) && (x <= trz.c))
         	    return 1.0;
         	 if ((x >= trz.a) && (x <= trz.b))
         	    return trz.l_slope * (x - trz.a);
         	 if ((x >= trz.c) && (x <= trz.d))
         	    return  trz.r_slope * (x - trz.d);

	 }  /* End switch  */

   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];


   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */

       weight = min_of (m_values,fz.no_of_inputs);

       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
   } /* end i  */


	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }

   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}

   fz->allocated = false;
   return;
}
