linked_list_of_ints: ./test/linked_list_of_ints_test.c
	clang -Wall test/linked_list_of_ints_test.c -o build/linked_list_of_ints_test
linked_list: ./test/linked_list_test.c
	clang -Wall test/linked_list_test.c -o build/linked_list_test
linked_list_example_frame_management: ./test/linked_list_example_frame_management.c
	clang -Wall test/linked_list_example_frame_management.c -o build/linked_list_example_frame_management
