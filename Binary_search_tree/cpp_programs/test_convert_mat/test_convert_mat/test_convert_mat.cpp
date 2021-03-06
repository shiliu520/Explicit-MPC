#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "C:\Users\schul\Documents\UDESC\TCC\TCC1\Programas MATLAB\GitHub\Explicit-MPC\Binary_search_tree\cpp_programs\convert_bst_mat_to_txt\mat.h"
#include <vector>
#include <fstream>
#include "C:\Users\schul\Documents\UDESC\TCC\TCC1\Programas MATLAB\GitHub\Explicit-MPC\Binary_search_tree\cpp_programs\convert_bst_mat_to_txt\convert_bst_mat_to_txt.h"
#include "C:\Users\schul\Documents\UDESC\TCC\TCC1\Programas MATLAB\GitHub\Explicit-MPC\Binary_search_tree\cpp_programs\convert_bst_mat_to_txt\convert_bst_mat_to_txt.cpp"
#include "C:\Users\schul\Documents\UDESC\TCC\TCC1\Programas MATLAB\GitHub\Explicit-MPC\Binary_search_tree\cpp_programs\explicit_mpc_bst\explicit_mpc_bst.h"
#include "C:\Users\schul\Documents\UDESC\TCC\TCC1\Programas MATLAB\GitHub\Explicit-MPC\Binary_search_tree\cpp_programs\explicit_mpc_bst\explicit_mpc_bst.cpp"



int main()
{	

	printf("test\n");
	
	struct_control_param control_param;
	std::vector< struct_regions > regions;
	std::vector< struct_bst > bst_nodes;
	std::vector <struct_ineq_set> ineq_set;

	get_struct_regions_from_mat(&control_param, &regions, "vt1_15_3_u3_linux/regions_15_3_u3_vt1.mat");
	
	get_struct_bst_from_mat(&control_param, &bst_nodes, "vt1_15_3_u3_linux/bst_nodes_15_3_u3_vt1.mat");

	get_struct_ineq_from_mat(&control_param, &ineq_set, "vt1_15_3_u3_linux/ineq_15_3_u3_inter_vt1.mat");
	
	export_regions_to_file(&control_param, &regions, "vt1_15_3_u3_linux/output_regions_15_3_u3_vt1.txt");
	std::vector<struct_regions> regions_check;
	//get_regions_from_file(&regions_check, "output_regions.txt");

	/*printf("\n\n Test Region\n");
	printf("%lf  %lf %lf %lf \n", regions[68].Kc[0], regions[68].Kc[1], regions[68].Kc[2], regions[68].Kc[3]);
	printf("%lf  %lf %lf %lf \n", regions_check[68].Kc[0], regions_check[68].Kc[1], regions_check[68].Kc[2], regions_check[68].Kc[3]);
	*/

	export_bst_to_file(&control_param, &bst_nodes, "vt1_15_3_u3_linux/output_bst_15_3_u3_vt1.txt");
	std::vector<struct_bst> bst_check;
	//get_bst_from_file(&bst_check, "output_bst.txt");
	/*
	printf("\n\n Test Node\n");
	printf("Ineq Node: %d   left: %d  right: %d  parent %d  size regions %d region 1: %d\n", bst_nodes[9].ineq_index, bst_nodes[9].left, bst_nodes[9].right, bst_nodes[9].parent_node, bst_nodes[9].regions.size(), bst_nodes[9].regions[0]);
	printf("Ineq Node: %d   left: %d  right: %d  parent %d  size regions %d region 1: %d\n", bst_check[9].ineq_index, bst_check[9].left, bst_check[9].right, bst_check[9].parent_node, bst_check[9].regions.size(), bst_check[9].regions[0]);
	*/

	export_ineq_set_to_file(&control_param, &ineq_set, "vt1_15_3_u3_linux/output_ineq_15_3_u3_vt1.txt");
	std::vector<struct_ineq_set> ineq_check;
	//get_ineq_set_from_file(&ineq_check, "output_ineq.txt");
	/*
	printf("\n\n Test Ineq\n");
	printf("A: %lf %lf b: %lf\n ", ineq_set[150].A[0], ineq_set[150].A[1], ineq_set[150].b);
	printf("A: %lf %lf b: %lf\n ", ineq_check[150].A[0], ineq_check[150].A[1], ineq_check[150].b);
	*/

	export_control_param_to_file(&control_param, "vt1_15_3_u3_linux/output_control_param_15_3_u3_vt1.txt");
	struct_control_param control_check;
	//get_control_param_file(&control_check, "output_control_param.txt");
	/*
	printf("\n\n Test Control param\n");
	printf("states: %d  controls: %d  regions: %d  nodes: %d  ineq: %d field_bst: %d  field_region: %d  field_ineq: %d\n", control_param.number_states, control_param.number_controls_actions, control_param.total_regions, control_param.total_nodes, control_param.total_ineq, control_param.number_fields_bst, control_param.number_fields_regions, control_param.number_fields_ineq);
	printf("states: %d  controls: %d  regions: %d  nodes: %d  ineq: %d field_bst: %d  field_region: %d  field_ineq: %d\n", control_check.number_states, control_check.number_controls_actions, control_check.total_regions, control_check.total_nodes, control_check.total_ineq, control_check.number_fields_bst, control_check.number_fields_regions, control_check.number_fields_ineq);
	*/
	/*
	double state_x[] = { 3, 0.1, -0.7, 0, 6, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
	//state_x = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//int index_region = index_region_evaluate_bst(state_x, &bst_nodes);
	size_t number_states = control_check.number_states;
	size_t number_controls_actions = control_check.number_controls_actions;
	int index_region = index_region_evaluate_bst(state_x, number_states, &bst_nodes, &ineq_set);

	printf("\n\n Test index regn");
	std::cout << index_region << std::endl;

	printf("\n\n Test Controls\n");
	double control_action[4];
	calculate_control_explicit_bst(control_action, state_x, number_states, number_controls_actions, &regions, index_region - 1);
	for (int it_control = 0; it_control < number_controls_actions; it_control++)
	{
		printf("%lf \n", control_action[it_control]);
	}*/

    return 0;
}

