import DecisionTree
import unittest

class TestDecisionTree(unittest.TestCase):

	@classmethod
	def setUpClass(cls):
		training_datafile = "py_test_data.csv"
		cls.dt = DecisionTree.DecisionTree( training_datafile = training_datafile,
											 csv_class_column_index = 2,
											 csv_columns_for_features = [3,4,5,6,7,8],
										     entropy_threshold = 0.01,
											 max_depth_desired = 8,
											 symbolic_to_numeric_cardinality_threshold = 10,
										   )
		cls.dt.get_training_data()
		cls.dt.calculate_first_order_probabilities()
		cls.dt.calculate_class_priors()

		cls.root_node = cls.dt.construct_decision_tree_classifier()

		cls.test_sample  = ['g2 = 4.2',
                			'grade = 2.3',
                			'gleason = 4',
                			'eet = 1.7',
                			'age = 55.0',
                			'ploidy = diploid']

		cls.classification = cls.dt.classify(cls.root_node, cls.test_sample)

	def test_get_training_data(self):		
		self.assertEqual(146, len(self.dt._training_data_dict.items()))

	def test_construct_decision_tree_classifier(self):
		self.assertTrue(self.root_node is not None)

	def test_classify(self):
		self.assertTrue(len(self.classification['solution_path']) > 0)

if __name__ == '__main__':
	suite = unittest.TestLoader().loadTestsFromTestCase(TestDecisionTree)
	unittest.TextTestRunner(verbosity=2).run(suite)
