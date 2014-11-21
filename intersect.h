#ifndef INTERSECT_H
#define INTERSECT_H


class Intersect
{
    public:
        Intersect(bool doesIntersect, float distance) :
            m_doesIntersect(doesIntersect),
            m_distance(distance) {}
        virtual ~Intersect();

        inline bool getDoesIntersect() const { return m_doesIntersect; }
        inline float getDistance() const { return m_distance; }

    protected:

    private:
        bool m_doesIntersect;
        float m_distance;
};

#endif // INTERSECT_H
