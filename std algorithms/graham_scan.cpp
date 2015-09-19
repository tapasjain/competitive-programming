//---------------------------graham scan pseudocode
# Three points are a counter-clockwise turn if ccw > 0, clockwise if
# ccw < 0, and collinear if ccw = 0 because ccw is a determinant that
# gives the signed area of the triangle formed by p1, p2 and p3.

function ccw(p1, p2, p3):
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x)

let N = number of points
let points[N+1] = the array of points
swap points[1] with the point with the lowest y-coordinate
sort points by polar angle with points[1]

# We want points[0] to be a sentinel point that will stop the loop.

let points[0] = points[N]

# M will denote the number of points on the convex hull.

let M = 1
for i = 2 to N:
	# Find next valid point on convex hull.
	while ccw(points[M-1], points[M], points[i]) <= 0:
		if M > 1:
			M -= 1

		# All points are collinear
		else if i == N:
			break
		else
			i += 1
	# Update M and swap points[i] to the correct place.
	M += 1
	swap points[M] with points[i]