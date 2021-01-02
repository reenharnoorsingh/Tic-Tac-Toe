import java.util.*;

public class TicTacToe {
    static ArrayList<Integer> playerPositions = new ArrayList<Integer>();// global variable for storing player positions
    static ArrayList<Integer> cpuPositions = new ArrayList<Integer>();// global variable for storing cpu positions

    public static void printBoard(char[][] gameBoard) { // prints the game board
        for (char[] row : gameBoard) {
            for (char c : row) {
                System.out.print(c);
            }
            System.out.println();
        }
    }

    public static void placement(char[][] gameBoard, int position, String user) { // places the symbol at the entered number
        char symbol = ' ';
        if (user.equals("player")) {
            symbol = 'X';
            playerPositions.add(position);// stores the player position
        } else if (user.equals("cpu")) {
            symbol = 'O';
            cpuPositions.add(position);// stores the cpu position
        }

        switch (position) {
            case 1:
                gameBoard[0][0] = symbol;
                break;
            case 2:
                gameBoard[0][2] = symbol;
                break;
            case 3:
                gameBoard[0][4] = symbol;
                break;
            case 4:
                gameBoard[2][0] = symbol;
                break;
            case 5:
                gameBoard[2][2] = symbol;
                break;
            case 6:
                gameBoard[2][4] = symbol;
                break;
            case 7:
                gameBoard[4][0] = symbol;
                break;
            case 8:
                gameBoard[4][2] = symbol;
                break;
            case 9:
                gameBoard[4][4] = symbol;
                break;
            default:
                break;
        }
    }

    public static String checkWinner() { // checks the winning cases

        List topRow = Arrays.asList(1, 2, 3);
        List midRow = Arrays.asList(4, 5, 6);
        List bottomRow = Arrays.asList(7, 8, 9);
        List leftCol = Arrays.asList(1, 4, 7);
        List midCol = Arrays.asList(2, 5, 8);
        List rightCol = Arrays.asList(3, 6, 9);
        List diagonal1 = Arrays.asList(1, 5, 9);
        List diagonal2 = Arrays.asList(3, 5, 7);

        List<List> winningConditions = new ArrayList<List>();
        winningConditions.add(topRow);
        winningConditions.add(midRow);
        winningConditions.add(bottomRow);
        winningConditions.add(leftCol);
        winningConditions.add(rightCol);
        winningConditions.add(midCol);
        winningConditions.add(diagonal1);
        winningConditions.add(diagonal2);

        for (List l : winningConditions) {
            if (playerPositions.containsAll(l)) {
                return "Congratulations! Player Wins!";
            } else if (cpuPositions.containsAll(l)) {
                return "CPU Wins :(";
            } else if (playerPositions.size() + cpuPositions.size() == 9) {
                return "Tie";
            }
        }
        return "";
    }

    public static void main(String[] args) {
        char[][] gameBoard = { { ' ', '|', ' ', '|', ' ' }, 
            { '-', '+', '-', '+', '-' }, 
            { ' ', '|', ' ', '|', ' ' },
            { '-', '+', '-', '+', '-' }, 
            { ' ', '|', ' ', '|', ' ' } };
        printBoard(gameBoard);
        while (true) {
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter your placement 1-9:");
            int playerPosition = scan.nextInt();
            while (playerPositions.contains(playerPosition) || cpuPositions.contains(playerPosition)) {//prevents the player to enter symbol in the occupied position
                System.out.println("Position Taken!");
                playerPosition = scan.nextInt();
            }

            placement(gameBoard, playerPosition, "player");

            String result = checkWinner();
            if (result.length() > 0) {
                printBoard(gameBoard);
                System.out.println(result);
                break;
            }

            Random rand = new Random();
            int cpuPosition = rand.nextInt(9) + 1;
            while (playerPositions.contains(cpuPosition) || cpuPositions.contains(cpuPosition)) { //prevents the cpu to add the symbol in the occupied position
                cpuPosition = rand.nextInt(9) + 1;
            }
            placement(gameBoard, cpuPosition, "cpu");

            printBoard(gameBoard);
            result = checkWinner();
            if (result.length() > 0) {
                printBoard(gameBoard);
                System.out.println(result);
                break;
            }
        }

    }
}
