class ParkingSystem(object):

    def __init__(self, big, medium, small):
        """
        :type big: int
        :type medium: int
        :type small: int
        """
        self.big = big
        self.medium = medium
        self.small = small

    def addCar(self, carType):
        """
        :type carType: int
        :rtype: bool
        """
        if carType == 1:
            if self.big <= 0:
                return False
            else:
                self.big -= 1
                return True
        elif carType == 2:
            if self.medium <= 0:
                return False
            else:
                self.medium -= 1
                return True
