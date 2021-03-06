/*

Aalto University Game Tools license

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#ifndef NORMALDISTRIBUTION_H
#define NORMALDISTRIBUTION_H
#include <Eigen/Eigen>
#include <vector>

namespace AaltoGames
{

	class NormalDistribution{

	public:

		Eigen::VectorXd mu;
		Eigen::MatrixXd covariance;
		Eigen::MatrixXd precisionMatrix;
		Eigen::MatrixXd choleskyOfCovarianceMatrix;
		bool choleskyComputed;
		double scaling;


		//Initialize a one dimensional normal distribution to zero mean and unit variance
		NormalDistribution();

		//Initialize a normal distribution to the given mean and given covariance
	NormalDistribution(Eigen::VectorXd mu, Eigen::MatrixXd covariance);

		//Calculate the product with another normal distribution
		NormalDistribution productWithNormalDistribution(NormalDistribution& dist);

		//Calculate the constant factor of the normal distribution
		void setScaling();

		double evaluateAtPoint(const Eigen::VectorXd& x);

		std::vector<Eigen::VectorXd> generateSamples(int amount);

		NormalDistribution conditionPart(NormalDistribution normIn, std::vector<int>& conditioningIndices, Eigen::VectorXd& values);

	};



	//Convert the precion matrix and shift parametrizised normal distribution to the standard form.
	NormalDistribution braketNotationToStandard(const Eigen::MatrixXd& precisionMatrix,const Eigen::VectorXd& shift);

} //AaltoGames
#endif //NORMALDISTRIBUTION_H
