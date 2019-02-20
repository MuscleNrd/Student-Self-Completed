/*
 *  Steven Oseguera - scoseguera@cpp.edu
 *  Project: MediaPlayer
 *  Driver.java - Created: December, 05, 2018 - 12:22 AM
 */

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;

public class Driver extends Application
{
	private File sound = new File("./res/sounds/trex.wav");
	private Media media = new Media(sound.toURI().toString());
	
	public static void main (String[] args)
	{
		launch(args);
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		// 3 buttons
		// media where we load a file to play
		// play file over and over until pause or stop
		// pause will stop the playing in mid play
		// stop will cause the play button to restart the sound file.
		
		// Done.
		
		Button btn_Play = new Button ("Play");
		Button btn_Pause = new Button ("Pause");
		Button btn_Stop = new Button ("Stop");
		
		MediaPlayer mp_mainPlayer = new MediaPlayer(media);
		
		btn_Play.setOnAction(event ->
		{
			mp_mainPlayer.stop();
			mp_mainPlayer.play();
		});
		
		btn_Pause.setOnAction(event ->
		{
			mp_mainPlayer.pause();
		});
		
		btn_Stop.setOnAction(event ->
		{
			mp_mainPlayer.stop();
		});
		
		mp_mainPlayer.setOnEndOfMedia(() ->
		{
			mp_mainPlayer.stop();
		});
		
		HBox hbox = new HBox(10, btn_Play, btn_Pause, btn_Stop);
		hbox.setAlignment(Pos.CENTER);
		hbox.setPadding(new Insets((25)));
		
		Scene scene = new Scene(hbox, 200,100);
		scene.setOnKeyPressed(event ->
		{
			if (event.getCode() == KeyCode.O)
			{
				FileChooser fc = new FileChooser();
				fc.setTitle("Get Media File");
				fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Audio Files", "*.wav","*.mp3","*.aac" ));
				sound = fc.showOpenDialog(primaryStage);
			}
		});
		
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
