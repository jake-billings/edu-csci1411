/**
 * Name: Jake Billings
 * Date: 11/16/2017
 * Class: CSCI 1411-001
 * Description: Scores class declaration; the scores class holds three scores
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#ifndef EDU_CSCI1411_SCORES_H
#define EDU_CSCI1411_SCORES_H

/**
 * @class Scores The Scores class contains three doubles representing scores
 *  on exams.
 *
 *  It implements an average function.
 */
class Scores {
public:
    /**
     * Declare an empty constructor
     */
    Scores();

    /**
     * Declare a full constructor that accepts all scores
     *
     * @param _scoreOne The value to initialize scoreOne
     * @param _scoreTwo The value to initialize scoreTwo
     * @param _scoreThree The value to initialize scoreThree
     */
    Scores(double scoreOne, double scoreTwo, double scoreThree);

private:
    /**
     * double scoreOne represents the first score
     */
    double scoreOne;

    /**
     * double scoreTwo represents the first score
     */
    double scoreTwo;

    /**
     * double scoreThree represents the first score
     */
    double scoreThree;

public:
    /**
    * The getAverage() function returns the average of the three scores stored in this
    *  Scores class object.
    *
    * @return a double representation of the average of the three scores
    */
    double getAverage();

    //Getters and setters
    double getScoreOne();

    void setScoreOne(double scoreOne);

    double getScoreTwo();

    void setScoreTwo(double scoreTwo);

    double getScoreThree();

    void setScoreThree(double scoreThree);
};


#endif //EDU_CSCI1411_SCORES_H
