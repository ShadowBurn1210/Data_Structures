// Saulitis_Leo_221RDB477

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

double read_file_poins();
double read_file_lines();

struct Point {
    double x;
    double y;

    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
};

struct Line {
    Point start;
    Point end;

    Line(Point startPoint, Point endPoint) : start(startPoint), end(endPoint) {}

    double lineLength(Point startPoint, Point endPoint) {
        start = startPoint;
        end = endPoint;

        double length = sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2));
        return length;
    };
};

struct Quadrilateral {
    Line line1;
    Line line2;
    Line line3;
    Line line4;

    Quadrilateral(Line l1, Line l2, Line l3, Line l4) : line1(l1), line2(l2), line3(l3), line4(l4) {}

    bool isSquare(Line l1, Line l2, Line l3, Line l4) {
        l1 = line1;
        l2 = line2;
        l3 = line3;
        l4 = line4;

        double length1 = l1.lineLength(l1.start, l1.end);
        double length2 = l2.lineLength(l2.start, l2.end);
        double length3 = l3.lineLength(l3.start, l3.end);
        double length4 = l4.lineLength(l4.start, l4.end);

        if (length1 == length2 && length2 == length3 && length3 == length4) {
        {
            return true;
        }
        } else {
            return false;
        }
    }

    double getArea(Line l1) const {
        l1 = line1;

        double length1 = l1.lineLength(l1.start, l1.end);
        double area = pow(length1, 2);

        return area;
    }
};

int main () {


    double max_area_points = read_file_poins();
    double max_area_lines = read_file_lines();

    cout << "Max area: " << max_area_points << endl;
    cout << "Max area: " << max_area_lines << endl;

    return 0;
}


double read_file_poins() {
    ifstream points_txt("C:\\Users\\37129\\Programming\\Programming Languages\\Data_Structures\\midterm\\points.txt");

    if (!points_txt.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; // or handle the error appropriately
    }


    string line;
    string delimiter = ",";

    vector<Point> points;
    vector<Quadrilateral> quadrilateral;

    double x, y;
    while (points_txt >> x >> y) {
        // Create a point from x and y and add it to the vector
        Point newPoint(x, y);
        points.push_back(newPoint);
    }

    for (int i = 0; i < points.size(); i+=4) {
        // Create a line from two points and add it to the vector
        Line line1(points[i], points[i+1]);
        Line line2(points[i+1], points[i+2]);
        Line line3(points[i+2], points[i+3]);
        Line line4(points[i+3], points[i]);

        Quadrilateral newQuadrilateral(line1, line2, line3, line4);
        quadrilateral.push_back(newQuadrilateral);
    }
    double max_area = 0.0;
    Quadrilateral biggest_square = quadrilateral[0];
    for (int i = 0; i < quadrilateral.size(); i++) {
        if (quadrilateral[i].isSquare(quadrilateral[i].line1, quadrilateral[i].line2, quadrilateral[i].line3, quadrilateral[i].line4)) {
            double area = quadrilateral[i].getArea(quadrilateral[i].line1);
            if(area > max_area) {
                max_area = area;
                Quadrilateral biggest_square = quadrilateral[i];

            }
        }
    }
    double length1 = biggest_square.line1.lineLength(biggest_square.line1.start, biggest_square.line1.end);
    cout << "Coordinates of the biggest square:" << endl;
    cout << "Point 1: (" << biggest_square.line1.start.x << ", " << biggest_square.line1.start.y << ")" << endl;
    cout << "Point 2: (" << biggest_square.line1.end.x << ", " << biggest_square.line1.end.y << ")" << endl;
    cout << "Point 3: (" << biggest_square.line2.end.x << ", " << biggest_square.line2.end.y << ")" << endl;
    cout << "Point 4: (" << biggest_square.line3.end.x << ", " << biggest_square.line3.end.y << ")" << endl;
    cout << "Side length of the square: " << length1 << endl;

    return max_area;
}

double read_file_lines() {
    ifstream lines_csv("C:\\Users\\37129\\Programming\\Programming Languages\\Data_Structures\\midterm\\dirty_lines.csv");


    if (!lines_csv.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; // or handle the error appropriately
    }

    string line;
    string delimiter = ",";

    vector<Point> points;
    vector<Quadrilateral> quadrilateral;
    vector<double> cordinates;
//so while we get any lines from the file
    while (getline(lines_csv, line)) {
        vector<double> input_line;

        stringstream ss(line);
        vector<double> elements;
        double num1;
        while (ss >> num1) {
            elements.push_back(num1);
            if (ss.peek() == ',')
                ss.ignore();
        }
        if (elements.size() != 4) {
            cerr << "Invalid number of elements in the row" << endl;
            cout << "Row: " << line << endl;
            continue;
        }

        size_t pos = 0;
        string token;
        int num;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);

            try {
                num = stoi(token);
                cordinates.push_back(num);
            } catch (const std::invalid_argument &e) {

                cerr << "Invalid argument: " << e.what() << endl;
                line.erase(0, pos + delimiter.length());
                continue;
            }

            line.erase(0, pos + delimiter.length());
        }
        //we also have to handle whatever is left after last delimiter

        if (!line.empty()) {
            try {
                num = stoi(line);
                cordinates.push_back(num);
            } catch (const std::invalid_argument &e) {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
        }
        if (cordinates.size() == 8) {

            Point newPoint(cordinates[0], cordinates[1]);
            Point newPoint2(cordinates[2], cordinates[3]);
            Point newPoint3(cordinates[4], cordinates[5]);
            Point newPoint4(cordinates[6], cordinates[7]);


            Line line1(newPoint, newPoint2);
            Line line2(newPoint2, newPoint3);
            Line line3(newPoint3, newPoint4);
            Line line4(newPoint4, newPoint);

            Quadrilateral newQuadrilateral(line1, line2, line3, line4);
            quadrilateral.push_back(newQuadrilateral);
            cordinates.clear();
        }

    }

    double max_area = 0.0;
    Quadrilateral biggest_square = quadrilateral[0];

    for (int i = 0; i < quadrilateral.size(); i++) {
        if (quadrilateral[i].isSquare(quadrilateral[i].line1, quadrilateral[i].line2, quadrilateral[i].line3, quadrilateral[i].line4)) {
            cout << "Square" << endl;
            double area = quadrilateral[i].getArea(quadrilateral[i].line1);
            if(area > max_area) {
                max_area = area;
                Quadrilateral biggest_square = quadrilateral[i];
            }
        }
    }
    double length1 = biggest_square.line1.lineLength(biggest_square.line1.start, biggest_square.line1.end);
    cout << "Coordinates of the biggest square:" << endl;
    cout << "Point 1: (" << biggest_square.line1.start.x << ", " << biggest_square.line1.start.y << ")" << endl;
    cout << "Point 2: (" << biggest_square.line1.end.x << ", " << biggest_square.line1.end.y << ")" << endl;
    cout << "Point 3: (" << biggest_square.line2.end.x << ", " << biggest_square.line2.end.y << ")" << endl;
    cout << "Point 4: (" << biggest_square.line3.end.x << ", " << biggest_square.line3.end.y << ")" << endl;
    cout << "Side length of the square: " << length1 << endl;

    return max_area;

}