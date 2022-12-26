#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h";
#include "Strassen.h"
#include "Functionality_matrices.h"
#include "Reversedmatrix_minors.h"

#include <time.h>

TEST_CASE("testing strassen`s algorithm") {

	std::clock_t start;
	std::clock_t finish;

	for (int i = 1024; i < 1025; i += 2) {
		Matrix* matrix1 = create_matrix_random_double(i,i);
		Matrix* matrix2 = create_matrix_random_double(i,i);

		if (check_matrices_for_multiply(matrix1, matrix2)) {
			//matrix1->print();
			//std::cout << std::endl;
			//matrix2->print();
			//std::cout << std::endl;

			start = clock();
			Matrix* not_strassen = matrix_multiply(matrix1, matrix2);
			//not_strassen->print();
			finish = clock();
			std::cout << " Regular algorithm for " << i << " x " << i << std::endl;
			//std::cout << " >>>Start : " << start <<"ms" << std::endl;
			//std::cout << " >>>Finish : " << finish << "ms" << std::endl;
			std::cout << " >>>Time taken : " << finish - start << "ms" << std::endl;
			std::cout << std::endl;

			start = clock();
			Matrix* strassen = strassen_multiply(matrix1, matrix2);
			//strassen->print();
			finish = clock();

			std::cout << " Strassen`s algorithm for " << i << " x " << i << std::endl;
			//std::cout << " >>>Start : " << start << "ms" <<std::endl;
			//std::cout << " >>>Finish : " << finish << "ms" << std::endl;
			std::cout << " >>>Time taken : " << finish - start << "ms" << std::endl;
			std::cout << std::endl;

			bool result = compare_matrices(not_strassen, strassen);
			delete not_strassen;
			delete strassen;
			CHECK(result);

		}
		else {
			std::cout << "incorrect matrices"<<std::endl;
		}
		delete matrix1;
		delete matrix2;
		

		
	}


}



TEST_CASE("Test 2") {
	
	for (int n = 3; n < 7; n++) {

		Matrix* matrix = create_matrix_random(n, n);
		
		std::cout << "Case " << n-2 << std::endl;
		std::cout << "Matrix:" << std::endl;
		matrix->print();
		std::cout << "\nMatrix determinant: " << matrix_det(matrix, n) << std::endl;
		std::cout << "\nReversed matrix:\n";
		
		Matrix* reversed = reverse_matrix(matrix, n);
		reversed->print();
		std::cout << std::endl;
		

		delete matrix;
		delete reversed;

	}
	
}