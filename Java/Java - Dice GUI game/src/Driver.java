import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import com.homework.*;

import javax.swing.*;
import java.util.HashMap;
import java.util.Map;


public class Driver extends Application
{
    public static void main(String[] args)
    {
        launch(args);
    }
    public static HBox hbox = new HBox();
    public static HBox hbox_buttons = new HBox();
    public static VBox vBox = new VBox();
    public static GridPane root = new GridPane();
    public static Button btn_Roll = new Button("Roll em!");
    public static Button btn_Skip = new Button("Skip");
    public static Label lbl_Annoucer = new Label("Please roll the dice!");
    public static Label lbl_turn_Counter = new Label("Turn: 0 / 3");
    public static Label lbl_Score_Literal = new Label ("No Score Yet!");
    public static Label lbl_Score_Integer = new Label ("Score: 0");
    public static Dice[] dice = new Dice[5];
    public static int turn_Number = 0;
    public static int max_turns = 3;
    public static Map<Integer,Integer> dice_count = new HashMap<>();
	
	public static void infoBox(String titleText, String headerText, String contextText)
	{
		Alert alert = new Alert(Alert.AlertType.INFORMATION);
		alert.setTitle(titleText);
		alert.setContentText(contextText);
		alert.setHeaderText(headerText);
		alert.showAndWait();
	}

    @Override
    public void start(Stage primaryStage) throws Exception
    {
        primaryStage.setTitle("Dice Pick em' Up!");
        
        init_buttons();
        init_labels();
        init_dice(dice);
        init_containers();

        Scene scene = new Scene(root);
        scene.getStylesheets().add("styles.css");
        
        primaryStage.setScene(scene);
		infoBox("Java Roll The Dice Game: v1.0", "Rules:", "" +
						"1. You get 3 turns to roll the dice. \n" +
						"2. Click on each die to \"Hold\" the die. \n" +
						"3. After your third roll, the game will alert you to your highest score! \n" +
				        "4. *NOTE* Your dice will be cleared on the very first roll, so don't try to cheat! :)");
        primaryStage.show();
    }

    private void print_Dice_Values()
    {
        for(Dice x : dice)
            System.out.println(x.getValue());

        System.out.println("-----------------");
    }

    private void init_buttons()
    {
        hbox_buttons.getChildren().add(btn_Roll);
        hbox_buttons.getChildren().add(btn_Skip);

        btn_Roll.setOnAction(event ->
        {
			computer_scores(dice);
			
        	if (turn_Number >= max_turns)
			{

				if (btn_Roll.getText().compareTo("Get Scores!") == 0)
				{
					infoBox("Scores!","Scores","Congrats!\n" + "You scored a " + lbl_Score_Literal.getText());
				}
				if (btn_Roll.getText().compareTo("Play Again!") == 0)
				{
					gameReset();
					return;
				}
				
				btn_Roll.setText("Play Again!");
				btn_Skip.setDisable(true);
				return;
			}
			
			
			this.turn_Number++;
			
            for (Dice x : dice)
                x.rollDice(turn_Number);

            lbl_Annoucer.setText("Select dice to keep or skip!");
			lbl_turn_Counter.setText("Turn: " + this.turn_Number + " / " + max_turns);
            btn_Roll.setDisable(true);

            print_Dice_Values();
        });

        btn_Skip.setOnAction(event ->
        {
            btn_Roll.setDisable(false);
            lbl_Annoucer.setText("Roll again!");
            
            if (turn_Number >= 3)
			{
				lbl_Annoucer.setText("Select your final dice and get your scores!");
				btn_Roll.setText("Get Scores!");
			}
        
        });
    }

    private void init_labels()
    {
    	lbl_Annoucer.setId("Announcer");
    	lbl_turn_Counter.setId("Turn_Counter");
    }

    private void init_containers()
    {
        hbox.setAlignment(Pos.CENTER);
        hbox_buttons.setAlignment(Pos.CENTER);
        hbox_buttons.setPadding(new Insets(50));


        vBox.getChildren().add(lbl_Annoucer);
        vBox.getChildren().add(lbl_turn_Counter);
        vBox.setAlignment(Pos.CENTER);


        root.setPadding(new Insets(100));
        root.setAlignment(Pos.CENTER);

        root.add(hbox,0,0);
        root.add(vBox,0,1);
        root.add(hbox_buttons,0,2);
        root.add(lbl_Score_Integer, 1,3);
        root.add(lbl_Score_Literal, 0,3);
    }

    private void init_dice(Dice [] dice)
    {
        for (int x = 0; x < 5; x++)
        {
            dice[x] = new Dice(x);
            hbox.getChildren().add(dice[x].getImage());
        }
    }
    
    private void computer_scores(Dice[] dice)
	{
		for (int x = 1; x <= 6; x++)
			dice_count.put(x,0);
		
		for (Dice x : dice)
			if (x.isSelected())
				dice_count.put(x.getValue(), dice_count.get(x.getValue()) + 1);
		
		for (Map.Entry<Integer,Integer> x : dice_count.entrySet())
			System.out.println(x.getValue());

		System.out.println("-----------------");
		
		// We now have all values of the dice
		// Begin scores:
		/*
			5 of a kind - 10 points
			Straight (5 numbers in a row i.e. 1, 2, 3, 4, 5 or 2, 3, 4, 5, 6) - 8 points
			Four of a Kind - 7 points
			Full House (3 of one kind, 2 of another) - 6 points
			3 of a kind - 5 points
			2 pair (2 of one kind, 2 of another, and 1 other value) - 4 points
			2 of a kind - 1 point
		 */
		
		// 5 of a Kind.
		if (dice_count.get(1) == 5 || dice_count.get(2) == 5 || dice_count.get(3) == 5 || dice_count.get(4) == 5 || dice_count.get(5) == 5 || dice_count.get(6) == 5)
		{
			lbl_Score_Integer.setText("Score: " + String.valueOf(10));
			lbl_Score_Literal.setText("5 of a Kind!");
			return;
		}
		
		else if (dice_count.get(1) == 1 && dice_count.get(2) == 1 && dice_count.get(3) == 1 && dice_count.get(4) == 1 && dice_count.get(5) == 1
				||
				dice_count.get(2) == 1 &&
				dice_count.get(3) == 1 &&
				dice_count.get(4) == 1 &&
				dice_count.get(5) == 1 &&
				dice_count.get(6) == 1 )
		{
			lbl_Score_Integer.setText(String.valueOf(8));
			lbl_Score_Literal.setText("Straight!");
			return;
		}
		
		// Four of a kind
		else if (dice_count.get(1) == 4 || dice_count.get(2) == 4 || dice_count.get(3) == 4 || dice_count.get(4) == 4 || dice_count.get(5) == 4 || dice_count.get(6) == 4)
		{
			lbl_Score_Integer.setText("Score: " + String.valueOf(7));
			lbl_Score_Literal.setText("4 of a Kind!");
			return;
		}
		
		// Full house
		else if (dice_count.get(1) == 3 || dice_count.get(2) == 3 || dice_count.get(3) == 3 || dice_count.get(4) == 3 || dice_count.get(5) == 3 || dice_count.get(6) == 3)
		{
			if (dice_count.get(1) == 2 || dice_count.get(2) == 2 || dice_count.get(3) == 2 || dice_count.get(4) == 2 || dice_count.get(5) == 2 || dice_count.get(6) == 2)
			{
				lbl_Score_Integer.setText("Score: " + String.valueOf(6));
				lbl_Score_Literal.setText("Full House!");
				return;
			}
		}
		
		// Three of a kind
		else if (dice_count.get(1) == 3 || dice_count.get(2) == 3 || dice_count.get(3) == 3 || dice_count.get(4) == 3 || dice_count.get(5) == 3 || dice_count.get(6) == 3)
		{
			lbl_Score_Integer.setText("Score: " + String.valueOf(6));
			lbl_Score_Literal.setText("3 of a Kind!");
			return;
		}
		
		// Two pair
		boolean pair1 = false;
		boolean pair2 = false;
		for (Map.Entry<Integer, Integer> x : dice_count.entrySet())
		{
			if (x.getValue() == 2)
			{
				if (pair1)
				{
					lbl_Score_Integer.setText("Score: " + String.valueOf(4));
					lbl_Score_Literal.setText("2 pair!");
					return;
				}
				else
					pair1 = true;
			}
		}
		
		// 2 of a kind
		if (dice_count.get(1) == 2 || dice_count.get(2) == 2 || dice_count.get(3) == 2 || dice_count.get(4) == 2 || dice_count.get(5) == 2 || dice_count.get(6) == 2)
		{
			lbl_Score_Integer.setText("Score: " + String.valueOf(2));
			lbl_Score_Literal.setText("2 of a Kind!");
		}
	}
	
	private void gameReset()
	{
		lbl_Annoucer.setText("Please roll the dice!");
		btn_Roll.setText("Roll em!");
		btn_Skip.setText("Skip");
		lbl_Score_Literal.setText("No Score Yet!");
		lbl_Score_Integer.setText(String.valueOf("0"));
		turn_Number = 0;
		btn_Skip.setDisable(false);
		lbl_turn_Counter.setText("Turn: " + this.turn_Number + " / " + max_turns);
		
		for ( int x = 0 ; x < 5; x++)
		{
			dice[x].setSelected(false);
			dice[x].setDie(x+1);
		}
	}
}
