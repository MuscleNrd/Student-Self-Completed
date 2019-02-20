package com.homework;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;

import java.io.File;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Dice
{
    private int value;
    private boolean selected;
    private ImageView image = null;

    private static Random rand = new Random(System.currentTimeMillis());

    private static final Map<Integer,String> diceUnselected;
    static
    {
        diceUnselected = new HashMap<>();
        diceUnselected.put(0, "Dice1.png");
        diceUnselected.put(1, "Dice2.png");
        diceUnselected.put(2, "Dice3.png");
        diceUnselected.put(3, "Dice4.png");
        diceUnselected.put(4, "Dice5.png");
        diceUnselected.put(5, "Dice6.png");
    }

    private static final Map<Integer,String> diceSelected;
    static
    {
        diceSelected = new HashMap<>();
        diceSelected.put(0, "Dice1Held.png");
        diceSelected.put(1, "Dice2Held.png");
        diceSelected.put(2, "Dice3Held.png");
        diceSelected.put(3, "Dice4Held.png");
        diceSelected.put(4, "Dice5Held.png");
        diceSelected.put(5, "Dice6Held.png");
    }

    public Dice(int value)
    {
        this.value = value + 1;
        this.image = new ImageView(new Image(new File(System.getProperty("user.dir") + "\\Dice Images\\" + diceUnselected.get(value)).toURI().toString()));
        this.selected = false;
        this.getImage().addEventHandler(MouseEvent.MOUSE_CLICKED, event ->
        {
            this.setSelected(!this.isSelected());
        });
        
    }

    public ImageView getImage() {
        return image;
    }

    public int getValue() {
        return value;
    }

    public boolean isSelected() {
        return selected;
    }

    public void rollDice(int turn)
    {
        if (turn >= 2)
            if (this.selected)
                return;
        
        this.value = rand.nextInt(6) + 1;

        File file = new File(System.getProperty("user.dir") + "\\Dice Images\\" + diceUnselected.get(this.value - 1));
        Image temp = new Image(file.toURI().toString());
        image.setImage(temp);
    }

    public void setSelected(boolean selected)
    {
        File file = new File(System.getProperty("user.dir") + "\\Dice Images\\" + (selected ? diceSelected.get(this.value - 1) : diceUnselected.get(this.value - 1)));
        Image temp = new Image(file.toURI().toString());
        image.setImage(temp);

        this.selected = selected;
    }
    
    public void setDie(int number)
    {
    	this.value = number;
    	
        File file = new File(System.getProperty("user.dir") + "\\Dice Images\\" + diceUnselected.get(number - 1));
        Image temp = new Image(file.toURI().toString());
        image.setImage(temp);
    }
}
