class SegmentTree {
public:
    // For a given Y line, this segment tree stores :

    vector<int> xCoordinates;   // all unique x coordinates
    int intervalCount;          // total intervals = xCoordinates.size() - 1
    vector<int> coverCount;
    vector<double> coveredWidth;

    // NOTE :
    // Each segment tree node owns a fixed X-range
    // coverCount[node] tells how many active rectangles fully cover this node's entire X-range.
    // (coverCount[node] > 0 means the whole range is covered)
    // coveredWidth[node] tells how much width of this node's x-range
    // is covered by at least one rectangle.

    SegmentTree(vector<int>& coords) {
        xCoordinates = coords;
        intervalCount = xCoordinates.size() - 1;
        coverCount.assign(4 * intervalCount, 0);
        coveredWidth.assign(4 * intervalCount, 0.0);
    }

    void updateRange(int queryLeftX, int queryRightX, int nodeLeftIdx, int nodeRightIdx, int delta, int nodeIndex) {
        // no overlap
        if (queryRightX <= xCoordinates[nodeLeftIdx] || queryLeftX  >= xCoordinates[nodeRightIdx + 1])
            return;

        // total overlap
        if (queryLeftX <= xCoordinates[nodeLeftIdx] &&
            queryRightX >= xCoordinates[nodeRightIdx + 1]) {
            coverCount[nodeIndex] += delta;
        } else {
            int mid = (nodeLeftIdx + nodeRightIdx) / 2;
            updateRange(queryLeftX, queryRightX, nodeLeftIdx, mid, delta, nodeIndex * 2 + 1);
            updateRange(queryLeftX, queryRightX, mid + 1, nodeRightIdx, delta, nodeIndex * 2 + 2);
        }

        // push-up
        if (coverCount[nodeIndex] > 0) {
            coveredWidth[nodeIndex] = xCoordinates[nodeRightIdx + 1] - xCoordinates[nodeLeftIdx];
        } else if (nodeLeftIdx == nodeRightIdx) {
            coveredWidth[nodeIndex] = 0;
        } else {
            coveredWidth[nodeIndex] = coveredWidth[nodeIndex * 2 + 1] + coveredWidth[nodeIndex * 2 + 2];
        }
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        set<int> xCoordinatesSet;
        vector<array<int, 4>> sweepEvents;
        //sweepEvent = {y, xLeft, xRight, type}
        //type = 1 , start of the square
        //type = -1, end of the square

        for (auto& square : squares) {
            int x = square[0];
            int y = square[1];
            int sideLength = square[2];

            xCoordinatesSet.insert(x);
            xCoordinatesSet.insert(x + sideLength);

            sweepEvents.push_back({y, x, x + sideLength, +1});
            sweepEvents.push_back({y + sideLength, x, x + sideLength, -1});
        }

        vector<int> xCoordinates(begin(xCoordinatesSet), end(xCoordinatesSet));

        SegmentTree segmentTree(xCoordinates);

        sort(sweepEvents.begin(), sweepEvents.end());

        double totalArea = 0.0;
        int previousY = sweepEvents[0][0];

        for (auto& event : sweepEvents) {
            int currentY  = event[0];
            int xLeft     = event[1];
            int xRight    = event[2];
            int eventType = event[3];

            double coveredX = segmentTree.coveredWidth[0]; //every time the root node will have the updated width
            totalArea += coveredX * (currentY - previousY);
            
            //Time to update the segment tree because we are sweeping up
            segmentTree.updateRange(xLeft, xRight, 0, segmentTree.intervalCount - 1, eventType, 0);

            previousY = currentY;
        }


        double accumulatedArea = 0.0;
        previousY = sweepEvents[0][0];

        SegmentTree segmentTree2(xCoordinates);

        for (auto& event : sweepEvents) {
            int currentY = event[0];
            int xLeft = event[1];
            int xRight = event[2];
            int eventType = event[3];

            double coveredX = segmentTree2.coveredWidth[0]; //The root contains updated width covered in x-axis
            double sliceArea = coveredX * (currentY - previousY);

            if (accumulatedArea + sliceArea >= totalArea / 2.0) {
                //it means somewhere here below lies the Y-line which divides the area in half
                //accumulatedArea + (deltaY*coveredX) = totalArea/2.0;
                //So, we have to return previousY + deltaY;
                double remaining = (totalArea / 2.0) - accumulatedArea;
                return previousY + remaining / coveredX;
            }

            accumulatedArea += sliceArea;

            //Since line is sweeping up, now we have to update the segment tree
            segmentTree2.updateRange(xLeft, xRight,0, segmentTree2.intervalCount - 1,eventType, 0);

            previousY = currentY;
        }

        // yaha flow aaega nahi kabhi
        return 0.0;
    }
};