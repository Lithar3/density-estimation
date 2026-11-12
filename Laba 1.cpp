#include <vector>
#include <cmath>
#include <fstream>
#include <random>
#include <iostream>
#include <matplot/matplot.h>

using namespace matplot;

double plt(double x) {
    double m = 1.0;
    double sigma = 0.2;
    double pi = 3.141592653589793;

    return 1.0 / (sigma * std::sqrt(2.0 * pi)) * std::exp(-std::pow(x - m, 2) / (2.0 * sigma * sigma));
}


double gen_rand(std::mt19937& rng, double m, double sigma) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    double sum = 0;

    for (int i = 0; i < 12; i++) {
        sum += dist(rng);
    }

    return sigma * (sum - 6.0) + m;
}


std::vector<double> generate_selection(int n, std::mt19937& rng, double m, double sigma) {
    std::vector<double> selection;

    for (int i = 0; i < n; i++) {
        selection.push_back(gen_rand(rng, m, sigma));
    }

    return selection;
}

std::vector<double> Kernel(std::vector<double>& selection, std::vector<double>& x_value, double h) {
	std::vector<double> result;
    double pi = 3.141592653589793;

    for (double x = 0.2; x <= 1.8; x += 0.004) {
		x_value.push_back(x);
        double sum = 0;
        for (double y : selection) {
            sum += std::exp(-std::pow(x - y, 2) / (2 * h * h));
        }
        result.push_back(1/(selection.size() * h * std::sqrt(2 * pi))* sum);
    }
	return result;
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int n = 10000;
    const double target_m = 1.0;
    const double target_sigma = 0.2;
    
    std::vector<double> x_value;

    std::vector<double> selection = generate_selection(n, gen, target_m, target_sigma);

    auto h = hist(selection, 50);
    h->normalization(histogram::normalization::pdf);
    h->face_color("green");
    h->edge_color("skyblue");
    h->line_width(0.8);

    hold(on);


    auto p = fplot(plt, std::array<double, 2>{0.2, 1.8});
    p->color("red");
    p->line_width(2);
   


 

    std::vector<double> result = Kernel(selection, x_value, 0.03);

    auto kde = plot(x_value, result);
    kde->color("blue");
    kde->line_width(2);

    hold(off);

    show();

    return 0;
}

