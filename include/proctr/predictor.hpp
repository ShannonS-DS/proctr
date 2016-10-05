
#ifndef PREDICTOR_HPP
#define PREDICTOR_HPP

#include <unordered_map>
#include "proctr/route.hpp"
#include "proctr/route_table.hpp"
#include "proctr/route_hash.hpp"

using namespace std;

template<size_t num_ts>
class Predictor
{
    using route_map = unordered_map<Route, int, RouteHash<num_ts>>;

    public:
        Predictor()
        {
        }

        Predictor(Correlations cors, Volumes vols, Stds stds)
        {
        }

        ~Predictor()
        {
        }

        /*
        * This function tracks the change in route demand over time therefore
        * calls to this function need to be ordered in time.
        *
        * This function maintains state. Beware!
        */
        void predict(route_map &demands, route_map &preds)
        {
            route_map diff;
            for (auto it : demands)
            {
                diff[it->first] = it->second - last[it->first];
            }

            Route max_route(num_ts, num_ts);
            for (Route r(0, 0); r < Route(num_ts, num_ts); r.next(num_ts))
            {
                for (Route s(0, 0); s < Route(num_ts, num_ts); s.next(num_ts))
                {
                }
            }
        }

    private:
        Correlations cors;
        Volumes vols;
        Stds stds;
        route_map last;
};

#endif
